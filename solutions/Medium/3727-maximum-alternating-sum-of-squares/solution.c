// ──────────────────────────────────────────────────
// Problem  : 3727. Maximum Alternating Sum of Squares
// Difficulty: Medium
// Tags     : Array, Greedy, Sorting
// Link     : https://leetcode.com/problems/maximum-alternating-sum-of-squares/
// Runtime  : 115 ms (beats 44%)
// Memory   : 45680000 (beats 13%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int compare(const void* a, const void* b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

long long maxAlternatingSum(int* nums, int numsSize) {
    long long* squares = (long long*)malloc(numsSize * sizeof(long long));
    for (int i = 0; i < numsSize; i++) {
        long long val = nums[i];
        squares[i] = val * val;
    }
    
    qsort(squares, numsSize, sizeof(long long), compare);
    
    long long total = 0;
    int mid = numsSize / 2;
    
    for (int i = 0; i < mid; i++) {
        total -= squares[i];
    }
    for (int i = mid; i < numsSize; i++) {
        total += squares[i];
    }
    
    free(squares);
    return total;
}