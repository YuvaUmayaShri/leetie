// ──────────────────────────────────────────────────
// Problem  : 73. Set Matrix Zeroes
// Difficulty: Medium
// Tags     : Array, Hash Table, Matrix
// Link     : https://leetcode.com/problems/set-matrix-zeroes/
// Runtime  : 0 ms (beats 100%)
// Memory   : 20000000 (beats 99%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    int m = matrixColSize[0];
    int firstRow = 0;
    int firstCol = 0;

    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) {
            firstRow = 1;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            firstCol = 1;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRow) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    if (firstCol) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}