// ──────────────────────────────────────────────────
// Problem  : 334. Increasing Triplet Subsequence
// Difficulty: Medium
// Tags     : Array, Greedy, Longest Increasing Subsequence
// Link     : https://leetcode.com/problems/increasing-triplet-subsequence/
// Runtime  : 2 ms (beats 30%)
// Memory   : 26976000 (beats 40%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <limits.h>

bool increasingTriplet(int* nums, int numsSize) {
    int first = INT_MAX;
    int second = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= first) {
            first = nums[i];
        } else if (nums[i] <= second) {
            second = nums[i];
        } else {
            return true;
        }
    }

    return false;
}