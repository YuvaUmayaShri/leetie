// ──────────────────────────────────────────────────
// Problem  : 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
// Difficulty: Medium
// Tags     : Array, Sliding Window
// Link     : https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8544000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
    int targetSum = k * threshold;
    int currentSum = 0;
    int count = 0;

    for (int i = 0; i < k; i++) {
        currentSum += arr[i];
    }

    if (currentSum >= targetSum) {
        count++;
    }

    for (int i = k; i < arrSize; i++) {
        currentSum += arr[i] - arr[i - k];
        if (currentSum >= targetSum) {
            count++;
        }
    }

    return count;
}