// ──────────────────────────────────────────────────
// Problem  : 132. Palindrome Partitioning II
// Difficulty: Hard
// Tags     : String, Dynamic Programming
// Link     : https://leetcode.com/problems/palindrome-partitioning-ii/
// Runtime  : 27 ms (beats 76%)
// Memory   : 22948000 (beats 34%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int minCut(char* s) {
    int n = strlen(s);
    if (n <= 1) return 0;

    bool** isPalindrome = (bool**)malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++) {
        isPalindrome[i] = (bool*)calloc(n, sizeof(bool));
    }

    int* dp = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int minCuts = i;
        for (int j = 0; j <= i; j++) {
            if (s[i] == s[j] && (i - j <= 2 || isPalindrome[j + 1][i - 1])) {
                isPalindrome[j][i] = true;
                minCuts = (j == 0) ? 0 : (dp[j - 1] + 1 < minCuts ? dp[j - 1] + 1 : minCuts);
            }
        }
        dp[i] = minCuts;
    }

    int result = dp[n - 1];

    for (int i = 0; i < n; i++) {
        free(isPalindrome[i]);
    }
    free(isPalindrome);
    free(dp);

    return result;
}