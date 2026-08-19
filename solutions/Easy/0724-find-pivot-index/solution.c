// ──────────────────────────────────────────────────
// Problem  : 724. Find Pivot Index
// Difficulty: Easy
// Tags     : Array, Prefix Sum
// Link     : https://leetcode.com/problems/find-pivot-index/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10168000 (beats 95%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int pivotIndex(int* nums, int numsSize) {
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    int leftSum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}