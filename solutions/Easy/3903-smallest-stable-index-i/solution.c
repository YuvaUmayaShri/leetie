// ──────────────────────────────────────────────────
// Problem  : 3903. Smallest Stable Index I
// Difficulty: Easy
// Tags     : Array, Prefix Sum
// Link     : https://leetcode.com/problems/smallest-stable-index-i/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10048000 (beats 41%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int firstStableIndex(int* nums, int numsSize, int k) {
    if (numsSize == 0) return -1;

    int* minSuffix = (int*)malloc(numsSize * sizeof(int));
    minSuffix[numsSize - 1] = nums[numsSize - 1];

    for (int i = numsSize - 2; i >= 0; i--) {
        minSuffix[i] = (nums[i] < minSuffix[i + 1]) ? nums[i] : minSuffix[i + 1];
    }

    int currMax = nums[0];
    int result = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > currMax) {
            currMax = nums[i];
        }

        if (currMax - minSuffix[i] <= k) {
            result = i;
            break;
        }
    }

    free(minSuffix);
    return result;
}