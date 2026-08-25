// ──────────────────────────────────────────────────
// Problem  : 583. Delete Operation for Two Strings
// Difficulty: Medium
// Tags     : String, Dynamic Programming, Longest Common Subsequence
// Link     : https://leetcode.com/problems/delete-operation-for-two-strings/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8512000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <string.h>
#include <stdlib.h>

int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);

    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)calloc(n + 1, sizeof(int));
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    int lcs = dp[m][n];

    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return m + n - 2 * lcs;
}