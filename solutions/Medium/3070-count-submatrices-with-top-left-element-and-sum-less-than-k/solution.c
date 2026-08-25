// ──────────────────────────────────────────────────
// Problem  : 3070. Count Submatrices with Top-Left Element and Sum Less Than k
// Difficulty: Medium
// Tags     : Array, Matrix, Prefix Sum
// Link     : https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/
// Runtime  : 17 ms (beats 47%)
// Memory   : 49636000 (beats 68%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) {
                grid[i][j] += grid[i - 1][j];
            }
            if (j > 0) {
                grid[i][j] += grid[i][j - 1];
            }
            if (i > 0 && j > 0) {
                grid[i][j] -= grid[i - 1][j - 1];
            }

            if (grid[i][j] <= k) {
                count++;
            } else {
                break;
            }
        }
    }

    return count;
}