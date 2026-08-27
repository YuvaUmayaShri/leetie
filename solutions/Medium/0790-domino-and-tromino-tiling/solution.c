// ──────────────────────────────────────────────────
// Problem  : 790. Domino and Tromino Tiling
// Difficulty: Medium
// Tags     : Dynamic Programming
// Link     : https://leetcode.com/problems/domino-and-tromino-tiling/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8528000 (beats 66%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int numTilings(int n) {
    if (n <= 2) return n;
    
    long MOD = 1e9 + 7;
    long dp[n + 1];
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
    }
    
    return dp[n];
}