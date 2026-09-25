// ──────────────────────────────────────────────────
// Problem  : 1818. Minimum Absolute Sum Difference
// Difficulty: Medium
// Tags     : Array, Binary Search, Sorting, Ordered Set
// Link     : https://leetcode.com/problems/minimum-absolute-sum-difference/
// Runtime  : 79 ms (beats 100%)
// Memory   : 19276000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <math.h>

int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minAbsoluteSumDiff(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int mod = 1000000007;
    int* sorted = (int*)malloc(nums1Size * sizeof(int));
    for (int i = 0; i < nums1Size; i++) {
        sorted[i] = nums1[i];
    }

    qsort(sorted, nums1Size, sizeof(int), compareInts);

    long long sumDiff = 0;
    int maxGain = 0;

    for (int i = 0; i < nums1Size; i++) {
        int diff = abs(nums1[i] - nums2[i]);
        sumDiff += diff;

        int left = 0;
        int right = nums1Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (sorted[mid] >= nums2[i]) {
                if (sorted[mid] - nums2[i] < diff) {
                    int gain = diff - (sorted[mid] - nums2[i]);
                    if (gain > maxGain) maxGain = gain;
                }
                right = mid - 1;
            } else {
                if (nums2[i] - sorted[mid] < diff) {
                    int gain = diff - (nums2[i] - sorted[mid]);
                    if (gain > maxGain) maxGain = gain;
                }
                left = mid + 1;
            }
        }
    }

    free(sorted);
    return (sumDiff - maxGain) % mod;
}