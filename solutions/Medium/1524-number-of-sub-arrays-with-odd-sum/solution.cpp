// ──────────────────────────────────────────────────
// Problem  : 1524. Number of Sub-arrays With Odd Sum
// Difficulty: Medium
// Tags     : Array, Math, Dynamic Programming, Prefix Sum
// Link     : https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
// Runtime  : 3 ms (beats 74%)
// Memory   : 111824000 (beats 92%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long odd = 0, even = 0, ans = 0;

        for (int x : arr) {
            if (x % 2 == 1) {
                long long newOdd = even + 1;
                long long newEven = odd;
                odd = newOdd;
                even = newEven;
            } else {
                even = even + 1;
            }
            ans = (ans + odd) % MOD;
        }

        return (int) ans;
    }
};