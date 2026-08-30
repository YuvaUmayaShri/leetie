// ──────────────────────────────────────────────────
// Problem  : 747. Largest Number At Least Twice of Others
// Difficulty: Easy
// Tags     : Array, Sorting
// Link     : https://leetcode.com/problems/largest-number-at-least-twice-of-others/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8776000 (beats 77%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int dominantIndex(int* nums, int numsSize) {
    int maxIdx = 0;
    int secondMax = -1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[maxIdx]) {
            secondMax = nums[maxIdx];
            maxIdx = i;
        } else if (nums[i] > secondMax) {
            secondMax = nums[i];
        }
    }

    if (nums[maxIdx] >= 2 * secondMax) {
        return maxIdx;
    }

    return -1;
}