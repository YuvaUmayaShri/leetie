// ──────────────────────────────────────────────────
// Problem  : 462. Minimum Moves to Equal Array Elements II
// Difficulty: Medium
// Tags     : Array, Math, Sorting
// Link     : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Runtime  : 3 ms (beats 58%)
// Memory   : 9632000 (beats 47%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMoves2(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int median = nums[numsSize / 2];
    int moves = 0;
    
    for (int i = 0; i < numsSize; i++) {
        moves += abs(nums[i] - median);
    }
    
    return moves;
}