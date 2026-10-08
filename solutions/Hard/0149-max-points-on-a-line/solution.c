// ──────────────────────────────────────────────────
// Problem  : 149. Max Points on a Line
// Difficulty: Hard
// Tags     : Array, Hash Table, Math, Geometry, Euclidean Algorithm, Greatest Common Divisor
// Link     : https://leetcode.com/problems/max-points-on-a-line/
// Runtime  : 53 ms (beats 14%)
// Memory   : 9484000 (beats 91%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 2) {
        return pointsSize;
    }

    int max_overall = 0;

    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }

            int count = 0;
            for (int k = 0; k < pointsSize; k++) {
                int dx2 = points[k][0] - points[i][0];
                int dy2 = points[k][1] - points[i][1];

                if (dx * dy2 == dy * dx2) {
                    count++;
                }
            }

            if (count > max_overall) {
                max_overall = count;
            }
        }
    }

    return max_overall;
}