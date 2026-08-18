// ──────────────────────────────────────────────────
// Problem  : 769. Max Chunks To Make Sorted
// Difficulty: Medium
// Tags     : Array, Stack, Greedy, Sorting, Monotonic Stack
// Link     : https://leetcode.com/problems/max-chunks-to-make-sorted/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8452000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int maxChunksToSorted(int* arr, int arrSize) {
    int max_val = 0;
    int chunks = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (max_val == i) {
            chunks++;
        }
    }

    return chunks;
}