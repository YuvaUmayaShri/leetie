// ──────────────────────────────────────────────────
// Problem  : 3077. Maximum Strength of K Disjoint Subarrays
// Difficulty: Hard
// Tags     : Array, Dynamic Programming, Prefix Sum
// Link     : https://leetcode.com/problems/maximum-strength-of-k-disjoint-subarrays/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8688000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <limits.h>

long long maximumStrength(int* nums, int numsSize, int k) {
    int n = numsSize;
    long long INF = 1e18;
    
    long long* dp0 = (long long*)malloc((k + 1) * sizeof(long long));
    long long* dp1 = (long long*)malloc((k + 1) * sizeof(long long));
    
    for (int j = 1; j <= k; j++) {
        dp0[j] = -INF;
        dp1[j] = -INF;
    }
    dp0[0] = 0;
    dp1[0] = -INF;

    for (int i = 0; i < n; i++) {
        long long val = nums[i];
        for (int j = k; j >= 1; j--) {
            long long weight = (j % 2 == 1) ? (long long)(k - j + 1) : -(long long)(k - j + 1);
            long long term = val * weight;
            
            long long prev_dp0 = dp0[j];
            long long prev_dp1 = dp1[j];
            
            long long option1 = dp0[j - 1] != -INF ? dp0[j - 1] + term : -INF;
            long long option2 = prev_dp1 != -INF ? prev_dp1 + term : -INF;
            
            long long new_dp1 = (option1 > option2) ? option1 : option2;
            
            long long new_dp0 = prev_dp0;
            if (new_dp1 > new_dp0) {
                new_dp0 = new_dp1;
            }
            
            dp0[j] = new_dp0;
            dp1[j] = new_dp1;
        }
    }

    long long ans = dp0[k];
    free(dp0);
    free(dp1);
    return ans;
}