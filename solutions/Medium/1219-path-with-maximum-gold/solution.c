// ──────────────────────────────────────────────────
// Problem  : 1219. Path with Maximum Gold
// Difficulty: Medium
// Tags     : Array, Backtracking, Matrix
// Link     : https://leetcode.com/problems/path-with-maximum-gold/
// Runtime  : 466 ms (beats 10%)
// Memory   : 9900000 (beats 20%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int dfs(int** grid, int r, int c, int m, int n) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
        return 0;
    }

    int currentGold = grid[r][c];
    grid[r][c] = 0;

    int maxGoldFromHere = 0;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < 4; i++) {
        int nextGold = dfs(grid, r + dirs[i][0], c + dirs[i][1], m, n);
        if (nextGold > maxGoldFromHere) {
            maxGoldFromHere = nextGold;
        }
    }

    grid[r][c] = currentGold;
    return currentGold + maxGoldFromHere;
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize) {
    int maxGold = 0;
    int m = gridSize;
    int n = gridColSize[0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0) {
                int gold = dfs(grid, i, j, m, n);
                if (gold > maxGold) {
                    maxGold = gold;
                }
            }
        }
    }

    return maxGold;
}