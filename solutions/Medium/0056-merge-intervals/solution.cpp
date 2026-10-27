// ──────────────────────────────────────────────────
// Problem  : 56. Merge Intervals
// Difficulty: Medium
// Tags     : Array, Sorting, Quicksort
// Link     : https://leetcode.com/problems/merge-intervals/
// Runtime  : 4 ms (beats 72%)
// Memory   : 23876000 (beats 60%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= prev[1]) {
                // Merge overlapping intervals
                prev[1] = max(prev[1], intervals[i][1]);
            } else {
                merged.push_back(prev);
                prev = intervals[i];
            }
        }

        merged.push_back(prev);
        return merged;
    }
};