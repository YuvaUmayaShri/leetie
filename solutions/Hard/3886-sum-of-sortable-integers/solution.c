// ──────────────────────────────────────────────────
// Problem  : 3886. Sum of Sortable Integers
// Difficulty: Hard
// Tags     : Array, Math, Sorting, Enumeration
// Link     : https://leetcode.com/problems/sum-of-sortable-integers/
// Runtime  : 1 ms (beats 0%)
// Memory   : 8148000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

long long sortableIntegers(int* nums, int numsSize) {
    long long total_sum = 0;
    
    int* sorted_nums = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        sorted_nums[i] = nums[i];
    }
    
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (sorted_nums[i] > sorted_nums[j]) {
                int temp = sorted_nums[i];
                sorted_nums[i] = sorted_nums[j];
                sorted_nums[j] = temp;
            }
        }
    }
    
    for (int k = 1; k <= numsSize; k++) {
        if (numsSize % k != 0) continue;
        
        int possible = 1;
        for (int i = 0; i < numsSize; i += k) {
            int block_valid = 0;
            
            for (int rot = 0; rot < k; rot++) {
                int match = 1;
                for (int j = 0; j < k; j++) {
                    if (nums[i + (j + rot) % k] != sorted_nums[i + j]) {
                        match = 0;
                        break;
                    }
                }
                if (match) {
                    block_valid = 1;
                    break;
                }
            }
            
            if (!block_valid) {
                possible = 0;
                break;
            }
        }
        
        if (possible) {
            total_sum += k;
        }
    }
    
    free(sorted_nums);
    return total_sum;
}