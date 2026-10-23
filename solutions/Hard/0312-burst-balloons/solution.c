// ──────────────────────────────────────────────────
// Problem  : 312. Burst Balloons
// Difficulty: Hard
// Tags     : Array, Dynamic Programming
// Link     : https://leetcode.com/problems/burst-balloons/
// Runtime  : 138 ms (beats 10%)
// Memory   : 10792000 (beats 42%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int maxCoins(int* nums, int numsSize) {
    int n = numsSize + 2;
    int* newNums = (int*)malloc(n * sizeof(int));
    newNums[0] = 1;
    newNums[n - 1] = 1;
    for (int i = 0; i < numsSize; i++) {
        newNums[i + 1] = nums[i];
    }

    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)calloc(n, sizeof(int));
    }

    for (int length = 1; length <= numsSize; length++) {
        for (int left = 1; left <= numsSize - length + 1; left++) {
            int right = left + length - 1;
            for (int k = left; k <= right; k++) {
                int coins = newNums[left - 1] * newNums[k] * newNums[right + 1];
                coins += dp[left][k - 1] + dp[k + 1][right];
                if (coins > dp[left][right]) {
                    dp[left][right] = coins;
                }
            }
        }
    }

    int ans = dp[1][numsSize];

    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    free(newNums);

    return ans;
}