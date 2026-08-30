// ──────────────────────────────────────────────────
// Problem  : 1913. Maximum Product Difference Between Two Pairs
// Difficulty: Easy
// Tags     : Array, Sorting, Quicksort
// Link     : https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
// Runtime  : 20 ms (beats 56%)
// Memory   : 10144000 (beats 47%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int maxProductDifference(int* nums, int numsSize) {
    int max1 = 0, max2 = 0;
    int min1 = 10001, min2 = 10001;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max1) {
            max2 = max1;
            max1 = nums[i];
        } else if (nums[i] > max2) {
            max2 = nums[i];
        }

        if (nums[i] < min1) {
            min2 = min1;
            min1 = nums[i];
        } else if (nums[i] < min2) {
            min2 = nums[i];
        }
    }

    return (max1 * max2) - (min1 * min2);
}