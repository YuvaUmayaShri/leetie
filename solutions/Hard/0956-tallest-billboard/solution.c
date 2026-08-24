// ──────────────────────────────────────────────────
// Problem  : 956. Tallest Billboard
// Difficulty: Hard
// Tags     : Array, Dynamic Programming, Meet in the Middle, Knapsack Problem, 0-1 Knapsack
// Link     : https://leetcode.com/problems/tallest-billboard/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8492000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int tallestBillboard(int* rods, int rodsSize) {
    int sum = 0;
    for (int i = 0; i < rodsSize; i++) {
        sum += rods[i];
    }

    int* dp = (int*)malloc((sum + 1) * sizeof(int));
    for (int i = 0; i <= sum; i++) {
        dp[i] = -1;
    }
    dp[0] = 0;

    for (int i = 0; i < rodsSize; i++) {
        int r = rods[i];
        int* cur = (int*)malloc((sum + 1) * sizeof(int));
        for (int j = 0; j <= sum; j++) {
            cur[j] = dp[j];
        }

        for (int d = 0; d <= sum; d++) {
            if (cur[d] < 0) continue;

            if (d + r <= sum) {
                dp[d + r] = MAX(dp[d + r], cur[d]);
            }

            int newDiff = abs(d - r);
            dp[newDiff] = MAX(dp[newDiff], cur[d] + MIN(d, r));
        }

        free(cur);
    }

    int result = dp[0];
    free(dp);
    return result;
}