// ──────────────────────────────────────────────────
// Problem  : 3524. Find X Value of Array I
// Difficulty: Medium
// Tags     : Array, Math, Dynamic Programming
// Link     : https://leetcode.com/problems/find-x-value-of-array-i/
// Runtime  : 25 ms (beats 33%)
// Memory   : 19892000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

long long* resultArray(int* nums, int numsSize, int k, int* returnSize) {
    long long* res = (long long*)calloc(k, sizeof(long long));
    *returnSize = k;
    
    long long dp[5] = {0};

    for (int i = 0; i < numsSize; i++) {
        long long next_dp[5] = {0};
        int val = nums[i] % k;
        
        next_dp[val]++;
        for (int r = 0; r < k; r++) {
            if (dp[r] > 0) {
                next_dp[(r * val) % k] += dp[r];
            }
        }
        
        for (int r = 0; r < k; r++) {
            dp[r] = next_dp[r];
            res[r] += dp[r];
        }
    }

    return res;
}