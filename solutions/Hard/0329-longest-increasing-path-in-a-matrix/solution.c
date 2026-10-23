// ──────────────────────────────────────────────────
// Problem  : 329. Longest Increasing Path in a Matrix
// Difficulty: Hard
// Tags     : Array, Dynamic Programming, Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort, Memoization, Matrix, Directed Acyclic Graph
// Link     : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Runtime  : 19 ms (beats 28%)
// Memory   : 13472000 (beats 38%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int dfs(int** matrix, int matrixSize, int* matrixColSize, int i, int j, int** memo) {
    if (memo[i][j] != 0) {
        return memo[i][j];
    }
    int m = matrixSize;
    int n = matrixColSize[0];
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maxLen = 1;
    for (int d = 0; d < 4; d++) {
        int x = i + dirs[d][0];
        int y = j + dirs[d][1];
        if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
            int len = 1 + dfs(matrix, matrixSize, matrixColSize, x, y, memo);
            if (len > maxLen) {
                maxLen = len;
            }
        }
    }
    memo[i][j] = maxLen;
    return maxLen;
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return 0;
    }
    int m = matrixSize;
    int n = matrixColSize[0];
    int** memo = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        memo[i] = (int*)calloc(n, sizeof(int));
    }
    int longest = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int len = dfs(matrix, matrixSize, matrixColSize, i, j, memo);
            if (len > longest) {
                longest = len;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        free(memo[i]);
    }
    free(memo);
    return longest;
}