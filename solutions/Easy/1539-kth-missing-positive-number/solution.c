// ──────────────────────────────────────────────────
// Problem  : 1539. Kth Missing Positive Number
// Difficulty: Easy
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/kth-missing-positive-number/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8464000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int findKthPositive(int* arr, int arrSize, int k) {
    int left = 0;
    int right = arrSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int missing = arr[mid] - (mid + 1);

        if (missing < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left + k;
}