// ──────────────────────────────────────────────────
// Problem  : 879. Profitable Schemes
// Difficulty: Hard
// Tags     : Array, Dynamic Programming, Knapsack Problem, 0-1 Knapsack
// Link     : https://leetcode.com/problems/profitable-schemes/
// Runtime  : 28 ms (beats 67%)
// Memory   : 9588000 (beats 50%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <string.h>

int profitableSchemes(int n, int minProfit, int* group, int groupSize, int* profit, int profitSize) {
    int MOD = 1000000007;
    int dp[101][101];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int k = 0; k < groupSize; k++) {
        int g = group[k];
        int p = profit[k];

        for (int i = n; i >= g; i--) {
            for (int j = minProfit; j >= 0; j--) {
                int prevProfit = j - p > 0 ? j - p : 0;
                dp[i][j] = (dp[i][j] + dp[i - g][prevProfit]) % MOD;
            }
        }
    }

    int totalSchemes = 0;
    for (int i = 0; i <= n; i++) {
        totalSchemes = (totalSchemes + dp[i][minProfit]) % MOD;
    }

    return totalSchemes;
}