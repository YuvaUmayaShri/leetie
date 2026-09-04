// ──────────────────────────────────────────────────
// Problem  : 1238. Circular Permutation in Binary Representation
// Difficulty: Medium
// Tags     : Math, Backtracking, Bit Manipulation
// Link     : https://leetcode.com/problems/circular-permutation-in-binary-representation/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8388000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int* circularPermutation(int n, int start, int* returnSize) {
    int total = 1 << n;
    int* result = (int*)malloc(total * sizeof(int));
    *returnSize = total;

    for (int i = 0; i < total; i++) {
        result[i] = start ^ (i ^ (i >> 1));
    }

    return result;
}