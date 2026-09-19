// ──────────────────────────────────────────────────
// Problem  : 1401. Circle and Rectangle Overlapping
// Difficulty: Medium
// Tags     : Math, Geometry
// Link     : https://leetcode.com/problems/circle-and-rectangle-overlapping/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8504000 (beats 13%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>

bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    int nearestX = xCenter;
        if (xCenter < x1) {
                nearestX = x1;
                    } else if (xCenter > x2) {
                            nearestX = x2;
                                }

                                    int nearestY = yCenter;
                                        if (yCenter < y1) {
                                                nearestY = y1;
                                                    } else if (yCenter > y2) {
                                                            nearestY = y2;
                                                                }

                                                                    int dx = xCenter - nearestX;
                                                                        int dy = yCenter - nearestY;

                                                                            return (dx * dx + dy * dy) <= (radius * radius);
                                                                            }