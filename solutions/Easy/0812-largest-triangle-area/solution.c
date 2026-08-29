// ──────────────────────────────────────────────────
// Problem  : 812. Largest Triangle Area
// Difficulty: Easy
// Tags     : Array, Math, Geometry, Polygons
// Link     : https://leetcode.com/problems/largest-triangle-area/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8540000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <math.h>

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    double maxArea = 0.0;
    
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            for (int k = j + 1; k < pointsSize; k++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int x3 = points[k][0], y3 = points[k][1];
                
                double area = 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
                
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }
    
    return maxArea;
}