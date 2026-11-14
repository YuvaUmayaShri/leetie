// ──────────────────────────────────────────────────
// Problem  : 3364. Minimum Positive Sum Subarray 
// Difficulty: Easy
// Tags     : Array, Sliding Window, Prefix Sum
// Link     : https://leetcode.com/problems/minimum-positive-sum-subarray/
// Runtime  : 4 ms (beats 21%)
// Memory   : 29300000 (beats 99%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                int len = j - i + 1;
                if (len >= l && len <= r && sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};