// ──────────────────────────────────────────────────
// Problem  : 733. Flood Fill
// Difficulty: Easy
// Tags     : Array, Depth-First Search, Breadth-First Search, Matrix
// Link     : https://leetcode.com/problems/flood-fill/
// Runtime  : 0 ms (beats 100%)
// Memory   : 14192000 (beats 14%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

static void dfs(int** image, int r, int c, int oldColor, int newColor, int imageSize, int imageColSize) {
    if (r < 0 || r >= imageSize || c < 0 || c >= imageColSize || image[r][c] != oldColor) {
        return;
    }

    image[r][c] = newColor;

    dfs(image, r + 1, c, oldColor, newColor, imageSize, imageColSize);
    dfs(image, r - 1, c, oldColor, newColor, imageSize, imageColSize);
    dfs(image, r, c + 1, oldColor, newColor, imageSize, imageColSize);
    dfs(image, r, c - 1, oldColor, newColor, imageSize, imageColSize);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int oldColor = image[sr][sc];

    if (oldColor != color) {
        dfs(image, sr, sc, oldColor, color, imageSize, imageColSize[0]);
    }

    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[i];
    }

    return image;
}