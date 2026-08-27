// ──────────────────────────────────────────────────
// Problem  : 926. Flip String to Monotone Increasing
// Difficulty: Medium
// Tags     : String, Dynamic Programming
// Link     : https://leetcode.com/problems/flip-string-to-monotone-increasing/
// Runtime  : 3 ms (beats 64%)
// Memory   : 10012000 (beats 82%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int minFlipsMonoIncr(char* s) {
    int count_ones = 0;
    int flips = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '1') {
            count_ones++;
        } else {
            flips = (flips + 1 < count_ones) ? flips + 1 : count_ones;
        }
    }

    return flips;
}