// ──────────────────────────────────────────────────
// Problem  : 665. Non-decreasing Array
// Difficulty: Medium
// Tags     : Array
// Link     : https://leetcode.com/problems/non-decreasing-array/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8600000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>

bool checkPossibility(int* nums, int numsSize) {
    int count = 0;
    
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            count++;
            if (count > 1) {
                return false;
            }
            if (i > 0 && nums[i - 1] > nums[i + 1]) {
                nums[i + 1] = nums[i];
            } else {
                nums[i] = nums[i + 1];
            }
        }
    }
    
    return true;
}