// ──────────────────────────────────────────────────
// Problem  : 667. Beautiful Arrangement II
// Difficulty: Medium
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/beautiful-arrangement-ii/
// Runtime  : 1 ms (beats 100%)
// Memory   : 46880000 (beats 12%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int[] constructArray(int n, int k) {
        int[] ans = new int[n];
        int left = 1;
        int right = n;

        for (int i = 0; i < n; i++) {
            if (k % 2 != 0) {
                ans[i] = left++;
            } else {
                ans[i] = right--;
            }
            if (k > 1) {
                k--;
            }
        }

        return ans;
    }
}