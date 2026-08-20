// ──────────────────────────────────────────────────
// Problem  : 883. Projection Area of 3D Shapes
// Difficulty: Easy
// Tags     : Array, Math, Geometry, Matrix
// Link     : https://leetcode.com/problems/projection-area-of-3d-shapes/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9732000 (beats 35%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int projectionArea(int** grid, int gridSize, int* gridColSize) {
    int totalArea = 0;

    for (int i = 0; i < gridSize; i++) {
        int maxRow = 0;
        int maxCol = 0;

        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j] > 0) {
                totalArea++;
            }
            if (grid[i][j] > maxRow) {
                maxRow = grid[i][j];
            }
            if (grid[j][i] > maxCol) {
                maxCol = grid[j][i];
            }
        }

        totalArea += maxRow + maxCol;
    }

    return totalArea;
}