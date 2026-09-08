// ──────────────────────────────────────────────────
// Problem  : 887. Super Egg Drop
// Difficulty: Hard
// Tags     : Math, Binary Search, Dynamic Programming
// Link     : https://leetcode.com/problems/super-egg-drop/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8628000 (beats 47%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int superEggDrop(int k, int n) {
    int dp[k + 1];
    for (int i = 0; i <= k; i++) {
        dp[i] = 0;
    }
    
    int moves = 0;
    while (dp[k] < n) {
        moves++;
        for (int i = k; i > 0; i--) {
            dp[i] = dp[i] + dp[i - 1] + 1;
        }
    }
    
    return moves;
}