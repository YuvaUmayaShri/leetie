// ──────────────────────────────────────────────────
// Problem  : 3550. Smallest Index With Digit Sum Equal to Index
// Difficulty: Easy
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/
// Runtime  : 0 ms (beats 100%)
// Memory   : 30956000 (beats 52%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            if (sum == i) {
                return i;
            }
        }
        return -1;
    }
};