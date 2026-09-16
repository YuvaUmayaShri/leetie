// ──────────────────────────────────────────────────
// Problem  : 1621. Number of Sets of K Non-Overlapping Line Segments
// Difficulty: Medium
// Tags     : Math, Dynamic Programming, Combinatorics, Prefix Sum
// Link     : https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
// Runtime  : 39 ms (beats 9%)
// Memory   : 16424000 (beats 9%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int numberOfSets(int n, int k) {
    long long MOD = 1000000007;
    long long dp[1005][1000] = {0};
    long long sum[1000] = {0};

    dp[0][0] = 1;

    for (int i = 1; i < n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= k; j++) {
            sum[j] = (sum[j] + dp[i - 1][j - 1]) % MOD;
            dp[i][j] = (dp[i - 1][j] + sum[j]) % MOD;
        }
    }

    return dp[n - 1][k];
}