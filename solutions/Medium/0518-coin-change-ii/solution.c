// ──────────────────────────────────────────────────
// Problem  : 518. Coin Change II
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Knapsack Problem, Complete Knapsack
// Link     : https://leetcode.com/problems/coin-change-ii/
// Runtime  : 61 ms (beats 7%)
// Memory   : 35168000 (beats 13%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int solve(int* coins, int coinsSize, int i, int amount, int** dp) {
    if (amount == 0)
        return 1;
    if (i == coinsSize || amount < 0)
        return 0;
    if (dp[i][amount] != -1)
        return dp[i][amount];

    int take = solve(coins, coinsSize, i, amount - coins[i], dp);
    int skip = solve(coins, coinsSize, i + 1, amount, dp);
    return dp[i][amount] = take + skip;
}

int change(int amount, int* coins, int coinsSize) {
    int** dp = (int**)malloc(coinsSize * sizeof(int*));
    for (int i = 0; i < coinsSize; i++) {
        dp[i] = (int*)malloc((amount + 1) * sizeof(int));

        for (int j = 0; j <= amount; j++)
            dp[i][j] = -1;
    }

    int ans = solve(coins, coinsSize, 0, amount, dp);
    for (int i = 0; i < coinsSize; i++)
        free(dp[i]);

    free(dp);
    return ans;
}