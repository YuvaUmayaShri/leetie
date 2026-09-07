// ──────────────────────────────────────────────────
// Problem  : 209. Minimum Size Subarray Sum
// Difficulty: Medium
// Tags     : Array, Binary Search, Sliding Window, Prefix Sum
// Link     : https://leetcode.com/problems/minimum-size-subarray-sum/
// Runtime  : 0 ms (beats 100%)
// Memory   : 13972000 (beats 66%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0;
    int sum = 0;
    int min_len = numsSize + 1;

    for (int right = 0; right < numsSize; right++) {
        sum += nums[right];

        while (sum >= target) {
            int current_len = right - left + 1;
            if (current_len < min_len) {
                min_len = current_len;
            }
            sum -= nums[left];
            left++;
        }
    }

    return (min_len == numsSize + 1) ? 0 : min_len;
}