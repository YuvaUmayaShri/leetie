// ──────────────────────────────────────────────────
// Problem  : 2267.  Check if There Is a Valid Parentheses String Path
// Difficulty: Hard
// Tags     : Array, Dynamic Programming, Matrix, Bracket Sequences
// Link     : https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/
// Runtime  : 6 ms (beats 83%)
// Memory   : 12596000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool visited[100][100][201];

bool dfs(char** grid, int m, int n, int r, int c, int balance) {
    if (grid[r][c] == '(') {
        balance++;
    } else {
        balance--;
    }

    if (balance < 0) {
        return false;
    }

    if (r == m - 1 && c == n - 1) {
        return balance == 0;
    }

    if (visited[r][c][balance]) {
        return false;
    }
    visited[r][c][balance] = true;

    if (r + 1 < m && dfs(grid, m, n, r + 1, c, balance)) {
        return true;
    }
    if (c + 1 < n && dfs(grid, m, n, r, c + 1, balance)) {
        return true;
    }

    return false;
}

bool hasValidPath(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
        return false;
    }

    memset(visited, 0, sizeof(visited));
    return dfs(grid, m, n, 0, 0, 0);
}