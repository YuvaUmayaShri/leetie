// ──────────────────────────────────────────────────
// Problem  : 1863. Sum of All Subset XOR Totals
// Difficulty: Easy
// Tags     : Array, Math, Backtracking, Bit Manipulation, Combinatorics, Enumeration
// Link     : https://leetcode.com/problems/sum-of-all-subset-xor-totals/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8684000 (beats 31%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int subsetXORSum(int* nums, int numsSize) {
    int orSum = 0;
    for (int i = 0; i < numsSize; i++) {
        orSum |= nums[i];
    }
    return orSum << (numsSize - 1);
}