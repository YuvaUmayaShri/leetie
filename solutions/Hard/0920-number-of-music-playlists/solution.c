// ──────────────────────────────────────────────────
// Problem  : 920. Number of Music Playlists
// Difficulty: Hard
// Tags     : Math, Dynamic Programming, Combinatorics
// Link     : https://leetcode.com/problems/number-of-music-playlists/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8372000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int numMusicPlaylists(int n, int goal, int k) {
    long long MOD = 1000000007;
    long long dp[goal + 1][n + 1];

    for (int i = 0; i <= goal; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 1; i <= goal; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j - 1] * (n - (j - 1))) % MOD;
            
            if (j > k) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % MOD;
            }
        }
    }

    return (int)dp[goal][n];
}