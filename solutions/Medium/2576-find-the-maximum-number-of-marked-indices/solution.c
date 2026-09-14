// ──────────────────────────────────────────────────
// Problem  : 2576. Find the Maximum Number of Marked Indices
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search, Greedy, Sorting
// Link     : https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8588000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxNumOfMarkedIndices(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int low = 0, high = numsSize / 2;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int possible = 1;

        for (int i = 0; i < mid; i++) {
            if (2 * nums[i] > nums[numsSize - mid + i]) {
                possible = 0;
                break;
            }
        }

        if (possible) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans * 2;
}