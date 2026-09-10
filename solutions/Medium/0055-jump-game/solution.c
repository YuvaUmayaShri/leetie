// ──────────────────────────────────────────────────
// Problem  : 55. Jump Game
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Greedy
// Link     : https://leetcode.com/problems/jump-game/
// Runtime  : 0 ms (beats 100%)
// Memory   : 11280000 (beats 71%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool canJump(int* nums, int numsSize) {
    int maxReach = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > maxReach) {
            return false;
        }

        if (i + nums[i] > maxReach) {
            maxReach = i + nums[i];
        }

        if (maxReach >= numsSize - 1) {
            return true;
        }
    }

    return true;
}