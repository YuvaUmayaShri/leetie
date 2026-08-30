// ──────────────────────────────────────────────────
// Problem  : 922. Sort Array By Parity II
// Difficulty: Easy
// Tags     : Array, Two Pointers, Sorting
// Link     : https://leetcode.com/problems/sort-array-by-parity-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8604000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int even = 0;
    int odd = 1;

    while (even < numsSize && odd < numsSize) {
        if (nums[even] % 2 == 0) {
            even += 2;
        } else if (nums[odd] % 2 != 0) {
            odd += 2;
        } else {
            int temp = nums[even];
            nums[even] = nums[odd];
            nums[odd] = temp;
            even += 2;
            odd += 2;
        }
    }

    *returnSize = numsSize;
    return nums;
}