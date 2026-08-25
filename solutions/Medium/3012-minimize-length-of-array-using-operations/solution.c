// ──────────────────────────────────────────────────
// Problem  : 3012. Minimize Length of Array Using Operations
// Difficulty: Medium
// Tags     : Array, Math, Greedy, Number Theory
// Link     : https://leetcode.com/problems/minimize-length-of-array-using-operations/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8328000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int minimumArrayLength(int* nums, int numsSize) {
    int min_val = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min_val) {
            min_val = nums[i];
        }
    }

    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == min_val) {
            count++;
        }
        if (nums[i] % min_val != 0) {
            return 1;
        }
    }

    return (count + 1) / 2;
}