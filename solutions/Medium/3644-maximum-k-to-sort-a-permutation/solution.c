// ──────────────────────────────────────────────────
// Problem  : 3644. Maximum K to Sort a Permutation
// Difficulty: Medium
// Tags     : Array, Bit Manipulation
// Link     : https://leetcode.com/problems/maximum-k-to-sort-a-permutation/
// Runtime  : 2 ms (beats 14%)
// Memory   : 19880000 (beats 86%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int sortPermutation(int* nums, int numsSize) {
    int k = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i) {
            if (k == -1) {
                k = nums[i];
            } else {
                k &= nums[i];
            }
        }
    }
    return (k == -1) ? 0 : k;
}