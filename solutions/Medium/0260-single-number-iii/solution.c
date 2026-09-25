// ──────────────────────────────────────────────────
// Problem  : 260. Single Number III
// Difficulty: Medium
// Tags     : Array, Bit Manipulation
// Link     : https://leetcode.com/problems/single-number-iii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10252000 (beats 6%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int* singleNumber(int* nums, int numsSize, int* returnSize) {
    long long xorSum = 0;
    for (int i = 0; i < numsSize; i++) {
        xorSum ^= nums[i];
    }

    long long diff = xorSum & (-xorSum);

    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] & diff) == 0) {
            num1 ^= nums[i];
        } else {
            num2 ^= nums[i];
        }
    }

    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = num1;
    result[1] = num2;

    *returnSize = 2;
    return result;
}