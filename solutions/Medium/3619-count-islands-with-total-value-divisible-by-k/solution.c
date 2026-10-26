// ──────────────────────────────────────────────────
// Problem  : 3619. Count Islands With Total Value Divisible by K
// Difficulty: Medium
// Tags     : Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
// Link     : https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
// Runtime  : 21 ms (beats 100%)
// Memory   : 29240000 (beats 75%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

void dfs(int** grid, int m, int n, int r, int c, long long* sum) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) return;
    *sum += grid[r][c];
    grid[r][c] = 0;
    
    dfs(grid, m, n, r + 1, c, sum);
    dfs(grid, m, n, r - 1, c, sum);
    dfs(grid, m, n, r, c + 1, sum);
    dfs(grid, m, n, r, c - 1, sum);
}

int countIslands(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];
    int count = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0) {
                long long island_sum = 0;
                dfs(grid, m, n, i, j, &island_sum);
                if (island_sum % k == 0) {
                    count++;
                }
            }
        }
    }
    
    return count;
}