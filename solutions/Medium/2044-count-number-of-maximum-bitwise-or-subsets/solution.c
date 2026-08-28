// ──────────────────────────────────────────────────
// Problem  : 2044. Count Number of Maximum Bitwise-OR Subsets
// Difficulty: Medium
// Tags     : Array, Backtracking, Bit Manipulation, Enumeration
// Link     : https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
// Runtime  : 8 ms (beats 62%)
// Memory   : 8680000 (beats 70%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

void dfs(int* nums, int numsSize, int index, int currentOr, int maxOr, int* count) {
    if (index == numsSize) {
        if (currentOr == maxOr) {
            (*count)++;
        }
        return;
    }
    dfs(nums, numsSize, index + 1, currentOr | nums[index], maxOr, count);
    dfs(nums, numsSize, index + 1, currentOr, maxOr, count);
}

int countMaxOrSubsets(int* nums, int numsSize) {
    int maxOr = 0;
    for (int i = 0; i < numsSize; i++) {
        maxOr |= nums[i];
    }
    
    int count = 0;
    dfs(nums, numsSize, 0, 0, maxOr, &count);
    return count;
}