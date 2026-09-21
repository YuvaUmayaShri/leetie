// ──────────────────────────────────────────────────
// Problem  : 413. Arithmetic Slices
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Sliding Window
// Link     : https://leetcode.com/problems/arithmetic-slices/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8624000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int numberOfArithmeticSlices(int* nums, int numsSize) {
    if (numsSize < 3) {
        return 0;
    }

    int totalSlices = 0;
    int currentSlices = 0;

    for (int i = 2; i < numsSize; i++) {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            currentSlices += 1;
            totalSlices += currentSlices;
        } else {
            currentSlices = 0;
        }
    }

    return totalSlices;
}