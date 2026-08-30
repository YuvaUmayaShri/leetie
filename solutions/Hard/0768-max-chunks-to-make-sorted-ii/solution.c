// ──────────────────────────────────────────────────
// Problem  : 768. Max Chunks To Make Sorted II
// Difficulty: Hard
// Tags     : Array, Stack, Greedy, Sorting, Monotonic Stack
// Link     : https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9416000 (beats 15%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxChunksToSorted(int* arr, int arrSize) {
    int* maxLeft = (int*)malloc(arrSize * sizeof(int));
    int* minRight = (int*)malloc(arrSize * sizeof(int));

    maxLeft[0] = arr[0];
    for (int i = 1; i < arrSize; i++) {
        maxLeft[i] = MAX(maxLeft[i - 1], arr[i]);
    }

    minRight[arrSize - 1] = arr[arrSize - 1];
    for (int i = arrSize - 2; i >= 0; i--) {
        minRight[i] = MIN(minRight[i + 1], arr[i]);
    }

    int chunks = 0;
    for (int i = 0; i < arrSize - 1; i++) {
        if (maxLeft[i] <= minRight[i + 1]) {
            chunks++;
        }
    }

    free(maxLeft);
    free(minRight);

    return chunks + 1;
}