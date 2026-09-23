// ──────────────────────────────────────────────────
// Problem  : 1658. Minimum Operations to Reduce X to Zero
// Difficulty: Medium
// Tags     : Array, Hash Table, Binary Search, Sliding Window, Prefix Sum
// Link     : https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// Runtime  : 7 ms (beats 16%)
// Memory   : 17136000 (beats 71%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minOperations(int* nums, int numsSize, int x) {
    long long totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    long long target = totalSum - x;

    if (target < 0) {
        return -1;
    }
    if (target == 0) {
        return numsSize;
    }

    int maxLen = -1;
    long long currentSum = 0;
    int left = 0;

    for (int right = 0; right < numsSize; right++) {
        currentSum += nums[right];

        while (currentSum > target && left <= right) {
            currentSum -= nums[left];
            left++;
        }

        if (currentSum == target) {
            maxLen = MAX(maxLen, right - left + 1);
        }
    }

    return (maxLen == -1) ? -1 : (numsSize - maxLen);
}