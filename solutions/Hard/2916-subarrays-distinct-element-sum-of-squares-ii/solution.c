// ──────────────────────────────────────────────────
// Problem  : 2916. Subarrays Distinct Element Sum of Squares II
// Difficulty: Hard
// Tags     : Array, Hash Table, Binary Indexed Tree, Segment Tree
// Link     : https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/
// Runtime  : 304 ms (beats 0%)
// Memory   : 53628000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

typedef struct {
    long long sum;
    long long lazy;
} Node;

typedef struct {
    int val;
    int index;
} Element;

Node *tree;

int cmp(const void *a, const void *b) {
    Element *x = (Element *)a;
    Element *y = (Element *)b;
    if (x->val != y->val) return (x->val > y->val) - (x->val < y->val);
    return (x->index > y->index) - (x->index < y->index);
}

void push(int node, long long l, long long r) {
    if (tree[node].lazy != 0) {
        long long mid = l + (r - l) / 2;
        int left_child = 2 * node;
        int right_child = 2 * node + 1;
        
        long long len_left = mid - l + 1;
        long long len_right = r - mid;
        
        tree[left_child].sum = (tree[left_child].sum + tree[node].lazy * len_left) % MOD;
        tree[left_child].lazy = (tree[left_child].lazy + tree[node].lazy) % MOD;
        
        tree[right_child].sum = (tree[right_child].sum + tree[node].lazy * len_right) % MOD;
        tree[right_child].lazy = (tree[right_child].lazy + tree[node].lazy) % MOD;
        
        tree[node].lazy = 0;
    }
}

void update(int node, long long l, long long r, long long ql, long long qr, long long val) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        long long len = r - l + 1;
        tree[node].sum = (tree[node].sum + val * len) % MOD;
        tree[node].lazy = (tree[node].lazy + val) % MOD;
        return;
    }
    push(node, l, r);
    long long mid = l + (r - l) / 2;
    update(2 * node, l, mid, ql, qr, val);
    update(2 * node + 1, mid + 1, r, ql, qr, val);
    tree[node].sum = (tree[2 * node].sum + tree[2 * node + 1].sum) % MOD;
}

long long query(int node, long long l, long long r, long long ql, long long qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return tree[node].sum;
    push(node, l, r);
    long long mid = l + (r - l) / 2;
    long long left_res = query(2 * node, l, mid, ql, qr);
    long long right_res = query(2 * node + 1, mid + 1, r, ql, qr);
    return (left_res + right_res) % MOD;
}

int sumCounts(int* nums, int numsSize) {
    Element *arr = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }
    qsort(arr, numsSize, sizeof(Element), cmp);
    
    int *last = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) last[i] = -1;
    
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && arr[i].val == arr[i-1].val) {
            last[arr[i].index] = arr[i-1].index;
        }
    }
    free(arr);
    
    tree = (Node*)calloc(4 * numsSize, sizeof(Node));
    
    long long ans = 0;
    long long cur = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int l = last[i] + 1;
        long long sum_val = query(1, 0, numsSize - 1, l, i);
        
        long long add = (2 * sum_val + (i - l + 1)) % MOD;
        cur = (cur + add) % MOD;
        ans = (ans + cur) % MOD;
        
        update(1, 0, numsSize - 1, l, i, 1);
    }
    
    free(last);
    free(tree);
    
    return (int)ans;
}