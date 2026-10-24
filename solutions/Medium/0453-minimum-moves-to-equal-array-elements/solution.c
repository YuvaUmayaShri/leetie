// ──────────────────────────────────────────────────
// Problem  : 453. Minimum Moves to Equal Array Elements
// Difficulty: Medium
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10012000 (beats 86%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int minMoves(int* nums, int numsSize) {
    int min = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    
    int moves = 0;
    for (int i = 0; i < numsSize; i++) {
        moves += nums[i] - min;
    }
    
    return moves;
}