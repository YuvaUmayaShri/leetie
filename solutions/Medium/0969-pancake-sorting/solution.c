// ──────────────────────────────────────────────────
// Problem  : 969. Pancake Sorting
// Difficulty: Medium
// Tags     : Array, Two Pointers, Greedy, Sorting
// Link     : https://leetcode.com/problems/pancake-sorting/
// Runtime  : 3 ms (beats 15%)
// Memory   : 11204000 (beats 8%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

void flip(int* arr, int k) {
    int i = 0, j = k - 1;
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int* pancakeSort(int* arr, int arrSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 10 * arrSize);
    *returnSize = 0;

    for (int curr = arrSize; curr > 1; curr--) {
        int max_idx = 0;
        for (int i = 1; i < curr; i++) {
            if (arr[i] > arr[max_idx]) {
                max_idx = i;
            }
        }

        if (max_idx == curr - 1) continue;

        if (max_idx != 0) {
            result[(*returnSize)++] = max_idx + 1;
            flip(arr, max_idx + 1);
        }

        result[(*returnSize)++] = curr;
        flip(arr, curr);
    }

    return result;
}