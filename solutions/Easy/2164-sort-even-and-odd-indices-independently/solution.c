// ──────────────────────────────────────────────────
// Problem  : 2164. Sort Even and Odd Indices Independently
// Difficulty: Easy
// Tags     : Array, Sorting
// Link     : https://leetcode.com/problems/sort-even-and-odd-indices-independently/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12332000 (beats 27%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int cmpAsc(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int cmpDesc(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int* sortEvenOdd(int* nums, int numsSize, int* returnSize) {
    int evenSize = (numsSize + 1) / 2;
    int oddSize = numsSize / 2;

    int* even = (int*)malloc(evenSize * sizeof(int));
    int* odd = (int*)malloc(oddSize * sizeof(int));

    int evenIdx = 0, oddIdx = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            even[evenIdx++] = nums[i];
        } else {
            odd[oddIdx++] = nums[i];
        }
    }

    qsort(even, evenSize, sizeof(int), cmpAsc);
    qsort(odd, oddSize, sizeof(int), cmpDesc);

    int* result = (int*)malloc(numsSize * sizeof(int));
    evenIdx = 0;
    oddIdx = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            result[i] = even[evenIdx++];
        } else {
            result[i] = odd[oddIdx++];
        }
    }

    free(even);
    free(odd);

    *returnSize = numsSize;
    return result;
}