// ──────────────────────────────────────────────────
// Problem  : 581. Shortest Unsorted Continuous Subarray
// Difficulty: Medium
// Tags     : Array, Two Pointers, Stack, Greedy, Sorting, Monotonic Stack
// Link     : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8356000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int findUnsortedSubarray(int* nums, int numsSize) {
    int max_val = nums[0];
    int min_val = nums[numsSize - 1];
    int right = -1;
    int left = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < max_val) {
            right = i;
        } else {
            max_val = nums[i];
        }

        int j = numsSize - 1 - i;
        if (nums[j] > min_val) {
            left = j;
        } else {
            min_val = nums[j];
        }
    }

    return (right == -1) ? 0 : (right - left + 1);
}