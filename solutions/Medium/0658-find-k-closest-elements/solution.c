// ──────────────────────────────────────────────────
// Problem  : 658. Find K Closest Elements
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search, Sliding Window, Sorting, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/find-k-closest-elements/
// Runtime  : 0 ms (beats 100%)
// Memory   : 20624000 (beats 89%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    int left = 0;
    int right = arrSize - k;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (x - arr[mid] > arr[mid + k] - x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = arr[left + i];
    }

    *returnSize = k;
    return result;
}