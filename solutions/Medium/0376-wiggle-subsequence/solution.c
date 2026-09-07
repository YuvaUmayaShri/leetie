// ──────────────────────────────────────────────────
// Problem  : 376. Wiggle Subsequence
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Greedy
// Link     : https://leetcode.com/problems/wiggle-subsequence/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8912000 (beats 11%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int wiggleMaxLength(int* nums, int numsSize) {
    if (numsSize < 2) {
        return numsSize;
    }

    int up = 1;
    int down = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            up = down + 1;
        } else if (nums[i] < nums[i - 1]) {
            down = up + 1;
        }
    }

    return up > down ? up : down;
}