// ──────────────────────────────────────────────────
// Problem  : 3498. Reverse Degree of a String
// Difficulty: Easy
// Tags     : String, Simulation
// Link     : https://leetcode.com/problems/reverse-degree-of-a-string/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9332000 (beats 41%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int reverseDegree(char* s) {
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int rev_pos = 26 - (s[i] - 'a');
        int str_pos = i + 1;
        sum += rev_pos * str_pos;
    }
    return sum;
}