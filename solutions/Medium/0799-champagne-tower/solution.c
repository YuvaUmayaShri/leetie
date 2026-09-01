// ──────────────────────────────────────────────────
// Problem  : 799. Champagne Tower
// Difficulty: Medium
// Tags     : Dynamic Programming
// Link     : https://leetcode.com/problems/champagne-tower/
// Runtime  : 3 ms (beats 0%)
// Memory   : 8560000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double champagneTower(int poured, int query_row, int query_glass) {
    double tower[101][101] = {0.0};
    tower[0][0] = (double)poured;

    for (int r = 0; r <= query_row; r++) {
        for (int c = 0; c <= r; c++) {
            if (tower[r][c] > 1.0) {
                double excess = (tower[r][c] - 1.0) / 2.0;
                tower[r][c] = 1.0;
                tower[r + 1][c] += excess;
                tower[r + 1][c + 1] += excess;
            }
        }
    }

    return tower[query_row][query_glass] > 1.0 ? 1.0 : tower[query_row][query_glass];
}