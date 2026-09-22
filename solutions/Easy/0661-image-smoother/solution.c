// ──────────────────────────────────────────────────
// Problem  : 661. Image Smoother
// Difficulty: Easy
// Tags     : Array, Matrix
// Link     : https://leetcode.com/problems/image-smoother/
// Runtime  : 5 ms (beats 47%)
// Memory   : 27276000 (beats 40%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {
    int m = imgSize;
    int n = imgColSize[0];

    int** result = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    *returnSize = m;

    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            int sum = 0;
            int count = 0;

            for (int r = i - 1; r <= i + 1; r++) {
                for (int c = j - 1; c <= j + 1; c++) {
                    if (r >= 0 && r < m && c >= 0 && c < n) {
                        sum += img[r][c];
                        count++;
                    }
                }
            }

            result[i][j] = sum / count;
        }
    }

    return result;
}