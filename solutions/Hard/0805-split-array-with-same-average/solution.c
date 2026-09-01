// ──────────────────────────────────────────────────
// Problem  : 805. Split Array With Same Average
// Difficulty: Hard
// Tags     : Array, Hash Table, Math, Dynamic Programming, Bit Manipulation, Meet in the Middle, Bitmask
// Link     : https://leetcode.com/problems/split-array-with-same-average/
// Runtime  : 47 ms (beats 71%)
// Memory   : 14284000 (beats 50%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <stdlib.h>

bool splitArraySameAverage(int* nums, int numsSize) {
    if (numsSize <= 1) return false;

    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    bool possible = false;
    for (int k = 1; k <= numsSize / 2; k++) {
        if ((totalSum * k) % numsSize == 0) {
            possible = true;
            break;
        }
    }
    if (!possible) return false;

    // dp[i] is a bitmask where the j-th bit is set if a sum of i can be formed using j elements
    int* dp = (int*)calloc(totalSum + 1, sizeof(int));
    dp[0] = 1; // 0 elements can form sum 0 (bit 0 is set)

    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        for (int s = totalSum - val; s >= 0; s--) {
            if (dp[s] > 0) {
                dp[s + val] |= (dp[s] << 1);
            }
        }
    }

    for (int k = 1; k <= numsSize / 2; k++) {
        if ((totalSum * k) % numsSize == 0) {
            int targetSum = (totalSum * k) / numsSize;
            if (dp[targetSum] & (1 << k)) {
                free(dp);
                return true;
            }
        }
    }

    free(dp);
    return false;
}