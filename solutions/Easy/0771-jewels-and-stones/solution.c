// ──────────────────────────────────────────────────
// Problem  : 771. Jewels and Stones
// Difficulty: Easy
// Tags     : Hash Table, String
// Link     : https://leetcode.com/problems/jewels-and-stones/
// Runtime  : N/A (beats 0%)
// Memory   : N/A (beats 0%)
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