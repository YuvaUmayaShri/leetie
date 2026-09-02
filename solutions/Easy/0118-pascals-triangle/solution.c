// ──────────────────────────────────────────────────
// Problem  : 118. Pascal's Triangle
// Difficulty: Easy
// Tags     : Array, Dynamic Programming
// Link     : https://leetcode.com/problems/pascals-triangle/
// Runtime  : 0 ms (beats 100%)
// Memory   : 11508000 (beats 70%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));

        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}