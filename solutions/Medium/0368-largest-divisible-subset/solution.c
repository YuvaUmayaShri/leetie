// ──────────────────────────────────────────────────
// Problem  : 368. Largest Divisible Subset
// Difficulty: Medium
// Tags     : Array, Math, Dynamic Programming, Sorting
// Link     : https://leetcode.com/problems/largest-divisible-subset/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8356000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

static int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), compareInts);

    int* dp = (int*)malloc(numsSize * sizeof(int));
    int* prev = (int*)malloc(numsSize * sizeof(int));

    int max_len = 1;
    int max_idx = 0;

    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            max_idx = i;
        }
    }

    int* result = (int*)malloc(max_len * sizeof(int));
    int curr = max_idx;
    for (int i = max_len - 1; i >= 0; i--) {
        result[i] = nums[curr];
        curr = prev[curr];
    }

    free(dp);
    free(prev);

    *returnSize = max_len;
    return result;
}