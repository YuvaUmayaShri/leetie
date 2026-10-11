// ──────────────────────────────────────────────────
// Problem  : 2778. Sum of Squares of Special Elements 
// Difficulty: Easy
// Tags     : Array, Enumeration
// Link     : https://leetcode.com/problems/sum-of-squares-of-special-elements/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10820000 (beats 6%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int sumOfSquares(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 1; i <= numsSize; i++) {
        if (numsSize % i == 0) {
            sum += nums[i - 1] * nums[i - 1];
        }
    }
    return sum;
}