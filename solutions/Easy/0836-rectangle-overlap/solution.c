// ──────────────────────────────────────────────────
// Problem  : 836. Rectangle Overlap
// Difficulty: Easy
// Tags     : Math, Geometry
// Link     : https://leetcode.com/problems/rectangle-overlap/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8656000 (beats 15%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
    return (rec1[0] < rec2[2] && rec1[2] > rec2[0] &&
            rec1[1] < rec2[3] && rec1[3] > rec2[1]);
}