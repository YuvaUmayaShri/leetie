// ──────────────────────────────────────────────────
// Problem  : 1385. Find the Distance Value Between Two Arrays
// Difficulty: Easy
// Tags     : Array, Two Pointers, Binary Search, Sorting
// Link     : https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
// Runtime  : 1 ms (beats 49%)
// Memory   : 16540000 (beats 76%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        auto far = [&](int a) {  // no b in [a - d, a + d]
            return ranges::all_of(arr2, [&](int b) { return abs(a - b) > d; });
        };
        return ranges::count_if(arr1, far);
    }
};