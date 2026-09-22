// ──────────────────────────────────────────────────
// Problem  : 807. Max Increase to Keep City Skyline
// Difficulty: Medium
// Tags     : Array, Greedy, Matrix
// Link     : https://leetcode.com/problems/max-increase-to-keep-city-skyline/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9800000 (beats 21%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int* max_row = (int*)calloc(n, sizeof(int));
    int* max_col = (int*)calloc(n, sizeof(int));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            max_row[r] = MAX(max_row[r], grid[r][c]);
            max_col[c] = MAX(max_col[c], grid[r][c]);
        }
    }

    int total_increase = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            total_increase += MIN(max_row[r], max_col[c]) - grid[r][c];
        }
    }

    free(max_row);
    free(max_col);

    return total_increase;
}