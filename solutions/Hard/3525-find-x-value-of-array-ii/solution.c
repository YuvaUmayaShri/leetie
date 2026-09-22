// ──────────────────────────────────────────────────
// Problem  : 3525. Find X Value of Array II
// Difficulty: Hard
// Tags     : Array, Math, Segment Tree
// Link     : https://leetcode.com/problems/find-x-value-of-array-ii/
// Runtime  : 446 ms (beats 0%)
// Memory   : 56112000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int count[5];
    int prod;
} Node;

static Node tree[400005];

static Node merge(Node left, Node right, int k) {
    Node res;
    for (int i = 0; i < k; i++) {
        res.count[i] = left.count[i];
    }
    for (int i = 0; i < k; i++) {
        if (right.count[i] > 0) {
            int new_rem = (left.prod * i) % k;
            res.count[new_rem] += right.count[i];
        }
    }
    res.prod = (left.prod * right.prod) % k;
    return res;
}

static void build(int node, int l, int r, int* nums, int k) {
    if (l == r) {
        for (int i = 0; i < k; i++) tree[node].count[i] = 0;
        int rem = nums[l] % k;
        tree[node].count[rem] = 1;
        tree[node].prod = rem;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * node, l, mid, nums, k);
    build(2 * node + 1, mid + 1, r, nums, k);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1], k);
}

static void update(int node, int l, int r, int idx, int val, int k) {
    if (l == r) {
        for (int i = 0; i < k; i++) tree[node].count[i] = 0;
        int rem = val % k;
        tree[node].count[rem] = 1;
        tree[node].prod = rem;
        return;
    }
    int mid = l + (r - l) / 2;
    if (idx <= mid) {
        update(2 * node, l, mid, idx, val, k);
    } else {
        update(2 * node + 1, mid + 1, r, idx, val, k);
    }
    tree[node] = merge(tree[2 * node], tree[2 * node + 1], k);
}

static Node query(int node, int l, int r, int ql, int qr, int k) {
    if (ql <= l && r <= qr) {
        return tree[node];
    }
    int mid = l + (r - l) / 2;
    if (qr <= mid) {
        return query(2 * node, l, mid, ql, qr, k);
    }
    if (ql > mid) {
        return query(2 * node + 1, mid + 1, r, ql, qr, k);
    }
    Node left_res = query(2 * node, l, mid, ql, qr, k);
    Node right_res = query(2 * node + 1, mid + 1, r, ql, qr, k);
    return merge(left_res, right_res, k);
}

int* resultArray(int* nums, int numsSize, int k, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    build(1, 0, numsSize - 1, nums, k);

    int* ans = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        int idx = queries[i][0];
        int val = queries[i][1];
        int start = queries[i][2];
        int x = queries[i][3];

        update(1, 0, numsSize - 1, idx, val, k);

        Node res = query(1, 0, numsSize - 1, start, numsSize - 1, k);
        ans[i] = res.count[x];
    }

    return ans;
}