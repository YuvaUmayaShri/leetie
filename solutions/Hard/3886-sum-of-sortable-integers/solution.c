// ──────────────────────────────────────────────────
// Problem  : 3886. Sum of Sortable Integers
// Difficulty: Hard
// Tags     : Array, Math, Sorting, Enumeration
// Link     : https://leetcode.com/problems/sum-of-sortable-integers/
// Runtime  : 17 ms (beats 96%)
// Memory   : 25192000 (beats 43%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

long long sortableIntegers(int* nums, int numsSize) {
    long long total_sum = 0;
    
    int* pref_max = (int*)malloc((numsSize + 1) * sizeof(int));
    int* suff_min = (int*)malloc((numsSize + 1) * sizeof(int));
    int* pref_drop = (int*)malloc((numsSize + 1) * sizeof(int));
    
    pref_max[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        pref_max[i + 1] = (pref_max[i] > nums[i]) ? pref_max[i] : nums[i];
    }
    
    suff_min[numsSize] = 2000000000;
    for (int i = numsSize - 1; i >= 0; i--) {
        suff_min[i] = (nums[i] < suff_min[i + 1]) ? nums[i] : suff_min[i + 1];
    }
    
    pref_drop[0] = 0;
    for (int i = 1; i < numsSize; i++) {
        pref_drop[i] = pref_drop[i - 1] + (nums[i - 1] > nums[i] ? 1 : 0);
    }
    
    for (int k = 1; k <= numsSize; k++) {
        if (numsSize % k != 0) continue;
        
        int possible = 1;
        
        for (int i = 0; i < numsSize; i += k) {
            int start = i;
            int end = i + k - 1;
            
            if (end + 1 < numsSize) {
                if (pref_max[end + 1] > suff_min[end + 1]) {
                    possible = 0;
                    break;
                }
            }
            
            int internal_drops = pref_drop[end] - pref_drop[start];
            int circular_drop = (nums[end] > nums[start]) ? 1 : 0;
            if (internal_drops + circular_drop > 1) {
                possible = 0;
                break;
            }
        }
        
        if (possible) {
            total_sum += k;
        }
    }
    
    free(pref_max);
    free(suff_min);
    free(pref_drop);
    
    return total_sum;
}