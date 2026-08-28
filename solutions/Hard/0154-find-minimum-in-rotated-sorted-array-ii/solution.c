// ──────────────────────────────────────────────────
// Problem  : 154. Find Minimum in Rotated Sorted Array II
// Difficulty: Hard
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9160000 (beats 50%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[right]) {
            right = mid;
        } else if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right--;
        }
    }

    return nums[left];
}