// ──────────────────────────────────────────────────
// Problem  : 1254. Number of Closed Islands
// Difficulty: Medium
// Tags     : Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
// Link     : https://leetcode.com/problems/number-of-closed-islands/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9800000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int dfs(int** grid, int gridSize, int gridColSize, int r, int c) {
    if (r < 0 || r >= gridSize || c < 0 || c >= gridColSize) {
        return 0;
    }
    if (grid[r][c] == 1) {
        return 1;
    }
    grid[r][c] = 1;
    int up = dfs(grid, gridSize, gridColSize, r - 1, c);
    int down = dfs(grid, gridSize, gridColSize, r + 1, c);
    int left = dfs(grid, gridSize, gridColSize, r, c - 1);
    int right = dfs(grid, gridSize, gridColSize, r, c + 1);
    return up && down && left && right;
}

int closedIsland(int** grid, int gridSize, int* gridColSize) {
    int cols = gridColSize[0];
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 0) {
                if (dfs(grid, gridSize, cols, i, j)) {
                    count++;
                }
            }
        }
    }
    return count;
}