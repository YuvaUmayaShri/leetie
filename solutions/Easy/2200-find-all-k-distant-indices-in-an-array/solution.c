// ──────────────────────────────────────────────────
// Problem  : 2200. Find All K-Distant Indices in an Array
// Difficulty: Easy
// Tags     : Array, Two Pointers
// Link     : https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12296000 (beats 60%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    int lastAdded = -1;

    for (int j = 0; j < numsSize; j++) {
        if (nums[j] == key) {
            int start = (j - k > lastAdded + 1) ? j - k : lastAdded + 1;
            int end = (j + k < numsSize - 1) ? j + k : numsSize - 1;

            for (int i = start; i <= end; i++) {
                res[count++] = i;
            }
            lastAdded = end;
        }
    }

    *returnSize = count;
    return res;
}