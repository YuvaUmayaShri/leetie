// ──────────────────────────────────────────────────
// Problem  : 740. Delete and Earn
// Difficulty: Medium
// Tags     : Array, Hash Table, Dynamic Programming
// Link     : https://leetcode.com/problems/delete-and-earn/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8580000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

int deleteAndEarn(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int max_val = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
    }

    int* points = (int*)calloc(max_val + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        points[nums[i]] += nums[i];
    }

    int take = 0;
    int skip = 0;

    for (int i = 0; i <= max_val; i++) {
        int takei = skip + points[i];
        int skipi = take > skip ? take : skip;

        take = takei;
        skip = skipi;
    }

    free(points);
    return take > skip ? take : skip;
}