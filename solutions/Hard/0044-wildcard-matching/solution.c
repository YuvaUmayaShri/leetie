// ──────────────────────────────────────────────────
// Problem  : 44. Wildcard Matching
// Difficulty: Hard
// Tags     : String, Dynamic Programming, Greedy, Recursion
// Link     : https://leetcode.com/problems/wildcard-matching/
// Runtime  : 50 ms (beats 11%)
// Memory   : 22092000 (beats 8%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isMatch(char *s, char *p) {
    int m = strlen(s);
    int n = strlen(p);

    bool **dp = (bool **)malloc((m + 1) * sizeof(bool *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (bool *)calloc(n + 1, sizeof(bool));
    }

    dp[0][0] = true;

    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    bool result = dp[m][n];

    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}