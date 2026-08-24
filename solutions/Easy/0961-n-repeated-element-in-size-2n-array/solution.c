// ──────────────────────────────────────────────────
// Problem  : 961. N-Repeated Element in Size 2N Array
// Difficulty: Easy
// Tags     : Array, Hash Table, Pigeonhole Principle
// Link     : https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10196000 (beats 91%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int repeatedNTimes(int* nums, int numsSize) {
    for (int i = 0; i < numsSize - 2; i++) {
        if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2]) {
            return nums[i];
        }
    }
    return nums[numsSize - 1];
}