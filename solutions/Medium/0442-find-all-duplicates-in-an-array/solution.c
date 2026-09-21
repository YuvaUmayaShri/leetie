// ──────────────────────────────────────────────────
// Problem  : 442. Find All Duplicates in an Array
// Difficulty: Medium
// Tags     : Array, Hash Table, Sorting
// Link     : https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Runtime  : 2 ms (beats 48%)
// Memory   : 25052000 (beats 59%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;

        if (nums[index] < 0) {
            result[*returnSize] = abs(nums[i]);
            (*returnSize)++;
        } else {
            nums[index] = -nums[index];
        }
    }

    return result;
}