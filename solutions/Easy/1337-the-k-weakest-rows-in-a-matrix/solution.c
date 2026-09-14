// ──────────────────────────────────────────────────
// Problem  : 1337. The K Weakest Rows in a Matrix
// Difficulty: Easy
// Tags     : Array, Binary Search, Sorting, Heap (Priority Queue), Matrix
// Link     : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Runtime  : 0 ms (beats 100%)
// Memory   : 11148000 (beats 4%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int countSoldiers(int* row, int cols) {
    int low = 0, high = cols - 1;
    int count = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (row[mid] == 1) {
            count = mid + 1;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return count;
}

int compare(const void* a, const void* b) {
    int* rowA = (int*)a;
    int* rowB = (int*)b;
    if (rowA[0] != rowB[0]) {
        return rowA[0] - rowB[0];
    }
    return rowA[1] - rowB[1];
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    int rowData[matSize][2];

    for (int i = 0; i < matSize; i++) {
        rowData[i][0] = countSoldiers(mat[i], matColSize[i]);
        rowData[i][1] = i;
    }

    qsort(rowData, matSize, sizeof(rowData[0]), compare);

    int* result = (int*)malloc(k * sizeof(int));
    *returnSize = k;

    for (int i = 0; i < k; i++) {
        result[i] = rowData[i][1];
    }

    return result;
}