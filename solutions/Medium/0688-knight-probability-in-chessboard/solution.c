// ──────────────────────────────────────────────────
// Problem  : 688. Knight Probability in Chessboard
// Difficulty: Medium
// Tags     : Dynamic Programming
// Link     : https://leetcode.com/problems/knight-probability-in-chessboard/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8928000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <string.h>

double knightProbability(int n, int k, int row, int column) {
    int moves[8][2] = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2}, {1, 2}, {2, -1}, {2, 1}
    };

    double dp[100][25][25];
    memset(dp, 0, sizeof(dp));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            dp[0][r][c] = 1.0;
        }
    }

    for (int m = 1; m <= k; m++) {
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                for (int i = 0; i < 8; i++) {
                    int nr = r + moves[i][0];
                    int nc = c + moves[i][1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        dp[m][r][c] += dp[m - 1][nr][nc] / 8.0;
                    }
                }
            }
        }
    }

    return dp[k][row][column];
}