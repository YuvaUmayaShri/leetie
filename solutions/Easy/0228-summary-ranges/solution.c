// ──────────────────────────────────────────────────
// Problem  : 228. Summary Ranges
// Difficulty: Easy
// Tags     : Array
// Link     : https://leetcode.com/problems/summary-ranges/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8680000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** result = (char**)malloc(numsSize * sizeof(char*));
    *returnSize = 0;
    
    int i = 0;
    while (i < numsSize) {
        int start = nums[i];
        while (i + 1 < numsSize && nums[i + 1] == nums[i] + 1) {
            i++;
        }
        int end = nums[i];
        
        result[*returnSize] = (char*)malloc(25 * sizeof(char));
        if (start == end) {
            sprintf(result[*returnSize], "%d", start);
        } else {
            sprintf(result[*returnSize], "%d->%d", start, end);
        }
        
        (*returnSize)++;
        i++;
    }
    
    return result;
}