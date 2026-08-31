// ──────────────────────────────────────────────────
// Problem  : 221. Maximal Square
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Matrix
// Link     : https://leetcode.com/problems/maximal-square/
// Runtime  : 8 ms (beats 29%)
// Memory   : 17088000 (beats 22%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return 0;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int max_side = 0;

    int** dp = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        dp[i] = (int*)calloc(cols, sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
                if (dp[i][j] > max_side) {
                    max_side = dp[i][j];
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        free(dp[i]);
    }
    free(dp);

    return max_side * max_side;
}