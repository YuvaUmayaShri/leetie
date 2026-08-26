// ──────────────────────────────────────────────────
// Problem  : 667. Beautiful Arrangement II
// Difficulty: Medium
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/beautiful-arrangement-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 41492000 (beats 0%)
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