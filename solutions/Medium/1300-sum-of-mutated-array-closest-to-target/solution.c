// ──────────────────────────────────────────────────
// Problem  : 1300. Sum of Mutated Array Closest to Target
// Difficulty: Medium
// Tags     : Array, Binary Search, Sorting
// Link     : https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8604000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findBestValue(int* arr, int arrSize, int target) {
    qsort(arr, arrSize, sizeof(int), compare);

    int prefixSum = 0;
    for (int i = 0; i < arrSize; i++) {
        int remainingElements = arrSize - i;
        int maxPossibleSum = prefixSum + arr[i] * remainingElements;

        if (maxPossibleSum >= target) {
            double remainingTarget = (double)(target - prefixSum) / remainingElements;
            int floorVal = (int)floor(remainingTarget);
            int ceilVal = (int)ceil(remainingTarget);

            int sum1 = prefixSum + floorVal * remainingElements;
            int sum2 = prefixSum + ceilVal * remainingElements;

            if (abs(sum1 - target) <= abs(sum2 - target)) {
                return floorVal;
            } else {
                return ceilVal;
            }
        }

        prefixSum += arr[i];
    }

    return arr[arrSize - 1];
}