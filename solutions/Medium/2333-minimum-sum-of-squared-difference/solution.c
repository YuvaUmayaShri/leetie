// ──────────────────────────────────────────────────
// Problem  : 2333. Minimum Sum of Squared Difference
// Difficulty: Medium
// Tags     : Array, Binary Search, Greedy, Sorting, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/minimum-sum-of-squared-difference/
// Runtime  : 11 ms (beats 75%)
// Memory   : 20880000 (beats 25%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

long long minSumSquareDiff(int* nums1, int nums1Size, int* nums2, int nums2Size, int k1, int k2) {
    long long total_k = (long long)k1 + k2;
    int max_diff = 0;
    for (int i = 0; i < nums1Size; i++) {
        int diff = abs(nums1[i] - nums2[i]);
        if (diff > max_diff) {
            max_diff = diff;
        }
    }

    int* count = (int*)calloc(max_diff + 1, sizeof(int));
    for (int i = 0; i < nums1Size; i++) {
        count[abs(nums1[i] - nums2[i])]++;
    }

    for (int d = max_diff; d > 0 && total_k > 0; d--) {
        if (count[d] > 0) {
            long long operations = (long long)count[d];
            if (operations <= total_k) {
                total_k -= operations;
                count[d - 1] += count[d];
                count[d] = 0;
            } else {
                count[d] -= total_k;
                count[d - 1] += total_k;
                total_k = 0;
            }
        }
    }

    long long ans = 0;
    for (int d = 1; d <= max_diff; d++) {
        if (count[d] > 0) {
            ans += (long long)count[d] * d * d;
        }
    }

    free(count);
    return ans;
}