// ──────────────────────────────────────────────────
// Problem  : 229. Majority Element II
// Difficulty: Medium
// Tags     : Array, Hash Table, Sorting, Counting, Boyer–Moore Majority Vote Algorithm
// Link     : https://leetcode.com/problems/majority-element-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 11204000 (beats 26%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int candidate1 = 0, candidate2 = 0;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        }
    }

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;

    if (count1 > numsSize / 3) {
        result[*returnSize] = candidate1;
        (*returnSize)++;
    }
    if (count2 > numsSize / 3) {
        result[*returnSize] = candidate2;
        (*returnSize)++;
    }

    return result;
}