// ──────────────────────────────────────────────────
// Problem  : 1637. Widest Vertical Area Between Two Points Containing No Points
// Difficulty: Easy
// Tags     : Array, Sorting
// Link     : https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8492000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    return p1[0] - p2[0];
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int*), compare);

    int maxWidth = 0;
    for (int i = 1; i < pointsSize; i++) {
        int width = points[i][0] - points[i - 1][0];
        if (width > maxWidth) {
            maxWidth = width;
        }
    }

    return maxWidth;
}