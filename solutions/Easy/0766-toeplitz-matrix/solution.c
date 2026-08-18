// ──────────────────────────────────────────────────
// Problem  : 766. Toeplitz Matrix
// Difficulty: Easy
// Tags     : Array, Matrix
// Link     : https://leetcode.com/problems/toeplitz-matrix/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10204000 (beats 48%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize - 1; i++) {
        for (int j = 0; j < matrixColSize[i] - 1; j++) {
            if (matrix[i][j] != matrix[i + 1][j + 1]) {
                return false;
            }
        }
    }
    return true;
}