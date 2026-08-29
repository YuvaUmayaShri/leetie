// ──────────────────────────────────────────────────
// Problem  : 1020. Number of Enclaves
// Difficulty: Medium
// Tags     : Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
// Link     : https://leetcode.com/problems/number-of-enclaves/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8512000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

void dfs(int** grid, int r, int c, int rows, int cols) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1) {
        return;
    }
    grid[r][c] = 0;
    dfs(grid, r + 1, c, rows, cols);
    dfs(grid, r - 1, c, rows, cols);
    dfs(grid, r, c + 1, rows, cols);
    dfs(grid, r, c - 1, rows, cols);
}

int numEnclaves(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    for (int i = 0; i < rows; i++) {
        if (grid[i][0] == 1) dfs(grid, i, 0, rows, cols);
        if (grid[i][cols - 1] == 1) dfs(grid, i, cols - 1, rows, cols);
    }

    for (int j = 0; j < cols; j++) {
        if (grid[0][j] == 1) dfs(grid, 0, j, rows, cols);
        if (grid[rows - 1][j] == 1) dfs(grid, rows - 1, j, rows, cols);
    }

    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }

    return count;
}