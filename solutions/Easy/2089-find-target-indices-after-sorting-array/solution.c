// ──────────────────────────────────────────────────
// Problem  : 2089. Find Target Indices After Sorting Array
// Difficulty: Easy
// Tags     : Array, Binary Search, Sorting
// Link     : https://leetcode.com/problems/find-target-indices-after-sorting-array/
// Runtime  : 4 ms (beats 0%)
// Memory   : 8596000 (beats 0%)
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