// ──────────────────────────────────────────────────
// Problem  : 324. Wiggle Sort II
// Difficulty: Medium
// Tags     : Array, Divide and Conquer, Greedy, Sorting, Quickselect
// Link     : https://leetcode.com/problems/wiggle-sort-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8432000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

void wiggleSort(int* nums, int numsSize) {
    int* temp = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        temp[i] = nums[i];
    }

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    int mid = (numsSize - 1) / 2;
    int end = numsSize - 1;

    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            nums[i] = temp[mid--];
        } else {
            nums[i] = temp[end--];
        }
    }

    free(temp);
}