// ──────────────────────────────────────────────────
// Problem  : 629. K Inverse Pairs Array
// Difficulty: Hard
// Tags     : Dynamic Programming
// Link     : https://leetcode.com/problems/k-inverse-pairs-array/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8356000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int kInversePairs(int n, int k) {
    int MOD = 1000000007;
    int dp[k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        int temp[k + 1];
        memset(temp, 0, sizeof(temp));
        long long windowSum = 0;

        for (int j = 0; j <= k; j++) {
            windowSum += dp[j];
            if (j >= i) {
                windowSum -= dp[j - i];
            }
            windowSum = (windowSum % MOD + MOD) % MOD;
            temp[j] = windowSum;
        }

        for (int j = 0; j <= k; j++) {
            dp[j] = temp[j];
        }
    }

    return dp[k];
}