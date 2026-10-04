// ──────────────────────────────────────────────────
// Problem  : 678. Valid Parenthesis String
// Difficulty: Medium
// Tags     : String, Dynamic Programming, Stack, Greedy, Bracket Sequences
// Link     : https://leetcode.com/problems/valid-parenthesis-string/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8496000 (beats 74%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool checkValidString(char* s) {
    int minOpen = 0;
    int maxOpen = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            minOpen++;
            maxOpen++;
        } else if (s[i] == ')') {
            minOpen--;
            maxOpen--;
        } else if (s[i] == '*') {
            minOpen--;
            maxOpen++;
        }

        if (maxOpen < 0) {
            return false;
        }

        if (minOpen < 0) {
            minOpen = 0;
        }
    }

    return minOpen == 0;
}