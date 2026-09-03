// ──────────────────────────────────────────────────
// Problem  : 2771. Longest Non-decreasing Subarray From Two Arrays
// Difficulty: Medium
// Tags     : Array, Dynamic Programming
// Link     : https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/
// Runtime  : 12 ms (beats 6%)
// Memory   : 20028000 (beats 21%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxNonDecreasingLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int dp1 = 1;
    int dp2 = 1;
    int maxLen = 1;

    for (int i = 1; i < nums1Size; i++) {
        int next_dp1 = 1;
        int next_dp2 = 1;

        if (nums1[i] >= nums1[i - 1]) {
            next_dp1 = MAX(next_dp1, dp1 + 1);
        }
        if (nums1[i] >= nums2[i - 1]) {
            next_dp1 = MAX(next_dp1, dp2 + 1);
        }

        if (nums2[i] >= nums1[i - 1]) {
            next_dp2 = MAX(next_dp2, dp1 + 1);
        }
        if (nums2[i] >= nums2[i - 1]) {
            next_dp2 = MAX(next_dp2, dp2 + 1);
        }

        dp1 = next_dp1;
        dp2 = next_dp2;

        maxLen = MAX(maxLen, MAX(dp1, dp2));
    }

    return maxLen;
}