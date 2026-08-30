// ──────────────────────────────────────────────────
// Problem  : 976. Largest Perimeter Triangle
// Difficulty: Easy
// Tags     : Array, Math, Greedy, Sorting, Quicksort, Polygons
// Link     : https://leetcode.com/problems/largest-perimeter-triangle/
// Runtime  : 14 ms (beats 67%)
// Memory   : 10636000 (beats 45%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = numsSize - 1; i >= 2; i--) {
        if (nums[i - 2] + nums[i - 1] > nums[i]) {
            return nums[i - 2] + nums[i - 1] + nums[i];
        }
    }

    return 0;
}