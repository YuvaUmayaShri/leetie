// ──────────────────────────────────────────────────
// Problem  : 518. Coin Change II
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Knapsack Problem, Complete Knapsack
// Link     : https://leetcode.com/problems/coin-change-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8284000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int change(int amount, int* coins, int coinsSize) {
    int* dp = (int*)calloc(amount + 1, sizeof(int));
    dp[0] = 1;

    for (int i = 0; i < coinsSize; i++) {
        int coin = coins[i];
        for (int j = coin; j <= amount; j++) {
            dp[j] += dp[j - coin];
        }
    }

    int result = dp[amount];
    free(dp);
    return result;
}