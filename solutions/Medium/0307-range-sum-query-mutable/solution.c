// ──────────────────────────────────────────────────
// Problem  : 307. Range Sum Query - Mutable
// Difficulty: Medium
// Tags     : Array, Divide and Conquer, Design, Binary Indexed Tree, Segment Tree, Sqrt Decomposition
// Link     : https://leetcode.com/problems/range-sum-query-mutable/
// Runtime  : 162 ms (beats 6%)
// Memory   : 102420000 (beats 6%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

typedef struct {
    int* tree;
    int* nums;
    int n;
} NumArray;

void updateTree(int* tree, int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = start + (end - start) / 2;
    if (idx <= mid) {
        updateTree(tree, 2 * node, start, mid, idx, val);
    } else {
        updateTree(tree, 2 * node + 1, mid + 1, end, idx, val);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void buildTree(int* tree, int* nums, int node, int start, int end) {
    if (start == end) {
        tree[node] = nums[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(tree, nums, 2 * node, start, mid);
    buildTree(tree, nums, 2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->n = numsSize;
    obj->nums = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        obj->nums[i] = nums[i];
    }
    obj->tree = (int*)calloc(4 * numsSize, sizeof(int));
    if (numsSize > 0) {
        buildTree(obj->tree, nums, 1, 0, numsSize - 1);
    }
    return obj;
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    obj->nums[index] = val;
    updateTree(obj->tree, 1, 0, obj->n - 1, index, val);
}

int queryTree(int* tree, int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return 0;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = start + (end - start) / 2;
    int p1 = queryTree(tree, 2 * node, start, mid, l, r);
    int p2 = queryTree(tree, 2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return queryTree(obj->tree, 1, 0, obj->n - 1, left, right);
}

void numArrayFree(NumArray* obj) {
    free(obj->tree);
    free(obj->nums);
    free(obj);
}