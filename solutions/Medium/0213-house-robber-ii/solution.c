// ──────────────────────────────────────────────────
// Problem  : 213. House Robber II
// Difficulty: Medium
// Tags     : Array, Dynamic Programming
// Link     : https://leetcode.com/problems/house-robber-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8620000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int robSimple(int* nums, int start, int end) {
    int prev1 = 0;
    int prev2 = 0;

    for (int i = start; i <= end; i++) {
        int temp = prev1;
        prev1 = (nums[i] + prev2 > prev1) ? nums[i] + prev2 : prev1;
        prev2 = temp;
    }

    return prev1;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];

    int case1 = robSimple(nums, 0, numsSize - 2);
    int case2 = robSimple(nums, 1, numsSize - 1);

    return (case1 > case2) ? case1 : case2;
}