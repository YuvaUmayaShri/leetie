// ──────────────────────────────────────────────────
// Problem  : 322. Coin Change
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Breadth-First Search, Knapsack Problem, Complete Knapsack
// Link     : https://leetcode.com/problems/coin-change/
// Runtime  : 20 ms (beats 95%)
// Memory   : 13364000 (beats 13%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = (int*)malloc((amount + 1) * sizeof(int));
    
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= i) {
                int subResult = dp[i - coins[j]];
                if (subResult != amount + 1 && subResult + 1 < dp[i]) {
                    dp[i] = subResult + 1;
                }
            }
        }
    }

    int result = (dp[amount] > amount) ? -1 : dp[amount];
    free(dp);
    return result;
}