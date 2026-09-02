// ──────────────────────────────────────────────────
// Problem  : 119. Pascal's Triangle II
// Difficulty: Easy
// Tags     : Array, Dynamic Programming
// Link     : https://leetcode.com/problems/pascals-triangle-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8496000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = (int*)malloc((*returnSize) * sizeof(int));

    row[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        row[i] = 1;
        for (int j = i - 1; j > 0; j--) {
            row[j] = row[j] + row[j - 1];
        }
    }

    return row;
}