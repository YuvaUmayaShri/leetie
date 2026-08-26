// ──────────────────────────────────────────────────
// Problem  : 672. Bulb Switcher II
// Difficulty: Medium
// Tags     : Math, Bit Manipulation, Depth-First Search, Breadth-First Search
// Link     : https://leetcode.com/problems/bulb-switcher-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 41860000 (beats 0%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int flipLights(int n, int presses) {
        if (presses == 0) return 1;
        if (n == 1) return 2;
        if (n == 2) return presses == 1 ? 3 : 4;
        
        if (presses == 1) return 4;
        if (presses == 2) return 7;
        return 8;
    }
}