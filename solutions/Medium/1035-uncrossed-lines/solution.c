// ──────────────────────────────────────────────────
// Problem  : 1035. Uncrossed Lines
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Longest Common Subsequence
// Link     : https://leetcode.com/problems/uncrossed-lines/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8556000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int dp[nums1Size + 1][nums2Size + 1];

    for (int i = 0; i <= nums1Size; i++) {
        for (int j = 0; j <= nums2Size; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                int a = dp[i - 1][j];
                int b = dp[i][j - 1];
                dp[i][j] = (a > b) ? a : b;
            }
        }
    }

    return dp[nums1Size][nums2Size];
}