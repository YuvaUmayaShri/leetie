// ──────────────────────────────────────────────────
// Problem  : 1636. Sort Array by Increasing Frequency
// Difficulty: Easy
// Tags     : Array, Hash Table, Sorting
// Link     : https://leetcode.com/problems/sort-array-by-increasing-frequency/
// Runtime  : 0 ms (beats 100%)
// Memory   : 11936000 (beats 63%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int freq[201];

int compare(const void* a, const void* b) {
    int valA = *(int*)a;
    int valB = *(int*)b;
    
    int freqA = freq[valA + 100];
    int freqB = freq[valB + 100];
    
    if (freqA != freqB) {
        return freqA - freqB;
    }
    
    return valB - valA;
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < 201; i++) {
        freq[i] = 0;
    }
    
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + 100]++;
    }
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    *returnSize = numsSize;
    return nums;
}