// ──────────────────────────────────────────────────
// Problem  : 52. N-Queens II
// Difficulty: Hard
// Tags     : Backtracking, Algorithm X
// Link     : https://leetcode.com/problems/n-queens-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8476000 (beats 75%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int totalSolutions;

void backtrack(int row, int n, int cols, int diag1, int diag2) {
    if (row == n) {
        totalSolutions++;
        return;
    }

    int availablePositions = ((1 << n) - 1) & ~(cols | diag1 | diag2);

    while (availablePositions) {
        int position = availablePositions & -availablePositions;
        availablePositions -= position;

        backtrack(row + 1, n, cols | position, (diag1 | position) << 1, (diag2 | position) >> 1);
    }
}

int totalNQueens(int n) {
    totalSolutions = 0;
    backtrack(0, n, 0, 0, 0);
    return totalSolutions;
}