// ──────────────────────────────────────────────────
// Problem  : 867. Transpose Matrix
// Difficulty: Easy
// Tags     : Array, Matrix, Simulation
// Link     : https://leetcode.com/problems/transpose-matrix/
// Runtime  : 0 ms (beats 100%)
// Memory   : 16084000 (beats 77%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    *returnSize = cols;
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));

    int** transposed = (int**)malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        (*returnColumnSizes)[i] = rows;
        transposed[i] = (int*)malloc(rows * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}