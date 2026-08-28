// ──────────────────────────────────────────────────
// Problem  : 2006. Count Number of Pairs With Absolute Difference K
// Difficulty: Easy
// Tags     : Array, Hash Table, Counting
// Link     : https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
// Runtime  : 1 ms (beats 99%)
// Memory   : 45008000 (beats 80%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int countKDifference(int[] nums, int k) {
        int count = 0;
        int[] freq = new int[101];

        for (int num : nums) {
            if (num - k >= 1) {
                count += freq[num - k];
            }
            if (num + k <= 100) {
                count += freq[num + k];
            }
            freq[num]++;
        }

        return count;
    }
}