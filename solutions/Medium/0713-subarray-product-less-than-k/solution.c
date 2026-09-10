// ──────────────────────────────────────────────────
// Problem  : 713. Subarray Product Less Than K
// Difficulty: Medium
// Tags     : Array, Binary Search, Sliding Window, Prefix Sum
// Link     : https://leetcode.com/problems/subarray-product-less-than-k/
// Runtime  : 7 ms (beats 16%)
// Memory   : 11972000 (beats 42%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if (k <= 1) {
        return 0;
    }

    int left = 0;
    int product = 1;
    int count = 0;

    for (int right = 0; right < numsSize; right++) {
        product *= nums[right];
        
        while (product >= k) {
            product /= nums[left];
            left++;
        }

        count += right - left + 1;
    }

    return count;
}