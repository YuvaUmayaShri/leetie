// ──────────────────────────────────────────────────
// Problem  : 1619. Mean of Array After Removing Some Elements
// Difficulty: Easy
// Tags     : Array, Sorting
// Link     : https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8700000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

double trimMean(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), compare);

    int k = arrSize / 20; // 5% of arrSize
    double sum = 0;
    int count = 0;

    for (int i = k; i < arrSize - k; i++) {
        sum += arr[i];
        count++;
    }

    return sum / count;
}