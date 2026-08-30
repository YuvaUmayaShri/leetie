// ──────────────────────────────────────────────────
// Problem  : 888. Fair Candy Swap
// Difficulty: Easy
// Tags     : Array, Hash Table, Binary Search, Sorting
// Link     : https://leetcode.com/problems/fair-candy-swap/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8772000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {
    int sumA = 0;
    int sumB = 0;

    for (int i = 0; i < aliceSizesSize; i++) {
        sumA += aliceSizes[i];
    }
    for (int i = 0; i < bobSizesSize; i++) {
        sumB += bobSizes[i];
    }

    int delta = (sumB - sumA) / 2;

    int hash[100001] = {0};
    for (int i = 0; i < bobSizesSize; i++) {
        hash[bobSizes[i]] = 1;
    }

    int* ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < aliceSizesSize; i++) {
        int target = aliceSizes[i] + delta;
        if (target >= 1 && target <= 100000 && hash[target]) {
            ans[0] = aliceSizes[i];
            ans[1] = target;
            return ans;
        }
    }

    return ans;
}