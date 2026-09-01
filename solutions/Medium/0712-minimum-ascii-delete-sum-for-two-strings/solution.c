// ──────────────────────────────────────────────────
// Problem  : 712. Minimum ASCII Delete Sum for Two Strings
// Difficulty: Medium
// Tags     : String, Dynamic Programming, Longest Common Subsequence
// Link     : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// Runtime  : 11 ms (beats 55%)
// Memory   : 9356000 (beats 62%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumDeleteSum(char* s1, char* s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    int dp[m + 1][n + 1];
    dp[0][0] = 0;

    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }

    for (int j = 1; j <= n; j++) {
        dp[0][j] = dp[0][j - 1] + s2[j - 1];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int delete_s1 = dp[i - 1][j] + s1[i - 1];
                int delete_s2 = dp[i][j - 1] + s2[j - 1];
                dp[i][j] = delete_s1 < delete_s2 ? delete_s1 : delete_s2;
            }
        }
    }

    return dp[m][n];
}