// ──────────────────────────────────────────────────
// Problem  : 611. Valid Triangle Number
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search, Greedy, Sorting
// Link     : https://leetcode.com/problems/valid-triangle-number/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8564000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int triangleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int count = 0;

    for (int i = numsSize - 1; i >= 2; i--) {
        int left = 0;
        int right = i - 1;

        while (left < right) {
            if (nums[left] + nums[right] > nums[i]) {
                count += (right - left);
                right--;
            } else {
                left++;
            }
        }
    }

    return count;
}