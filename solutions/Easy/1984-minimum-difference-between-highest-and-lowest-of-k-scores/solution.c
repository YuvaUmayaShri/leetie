// ──────────────────────────────────────────────────
// Problem  : 1984. Minimum Difference Between Highest and Lowest of K Scores
// Difficulty: Easy
// Tags     : Array, Sliding Window, Sorting
// Link     : https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8460000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int minimumDifference(int* nums, int numsSize, int k) {
    if (k == 1) return 0;

    qsort(nums, numsSize, sizeof(int), cmp);

    int minDiff = nums[k - 1] - nums[0];

    for (int i = 1; i <= numsSize - k; i++) {
        int currentDiff = nums[i + k - 1] - nums[i];
        if (currentDiff < minDiff) {
            minDiff = currentDiff;
        }
    }

    return minDiff;
}