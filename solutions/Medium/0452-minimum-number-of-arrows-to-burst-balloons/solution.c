// ──────────────────────────────────────────────────
// Problem  : 452. Minimum Number of Arrows to Burst Balloons
// Difficulty: Medium
// Tags     : Array, Greedy, Sorting
// Link     : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// Runtime  : 41 ms (beats 51%)
// Memory   : 37088000 (beats 89%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    int compare(const void* a, const void* b) {
        int* p1 = *(int**)a;
        int* p2 = *(int**)b;
        if (p1[1] == p2[1]) {
            return 0;
        }
        return p1[1] < p2[1] ? -1 : 1;
    }

    qsort(points, pointsSize, sizeof(int*), compare);

    int arrows = 1;
    long long prevEnd = points[0][1];

    for (int i = 1; i < pointsSize; i++) {
        if (points[i][0] > prevEnd) {
            arrows++;
            prevEnd = points[i][1];
        }
    }

    return arrows;
}