// ──────────────────────────────────────────────────
// Problem  : 3904. Smallest Stable Index II
// Difficulty: Medium
// Tags     : Array, Prefix Sum
// Link     : https://leetcode.com/problems/smallest-stable-index-ii/
// Runtime  : 4 ms (beats 67%)
// Memory   : 30404000 (beats 25%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int firstStableIndex(int* nums, int numsSize, int k) {
    int* suffMin = (int*)malloc(numsSize * sizeof(int));
    
    suffMin[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) {
        suffMin[i] = nums[i] < suffMin[i + 1] ? nums[i] : suffMin[i + 1];
    }

    int prefMax = nums[0];
    int result = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > prefMax) {
            prefMax = nums[i];
        }

        if (prefMax - suffMin[i] <= k) {
            result = i;
            break;
        }
    }

    free(suffMin);
    return result;
}