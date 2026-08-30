// ──────────────────────────────────────────────────
// Problem  : 2089. Find Target Indices After Sorting Array
// Difficulty: Easy
// Tags     : Array, Binary Search, Sorting
// Link     : https://leetcode.com/problems/find-target-indices-after-sorting-array/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9460000 (beats 35%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    int count = 0;
    int lessThan = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            count++;
        } else if (nums[i] < target) {
            lessThan++;
        }
    }

    *returnSize = count;
    int* result = (int*)malloc(count * sizeof(int));

    for (int i = 0; i < count; i++) {
        result[i] = lessThan + i;
    }

    return result;
}