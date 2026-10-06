// ──────────────────────────────────────────────────
// Problem  : 921. Minimum Add to Make Parentheses Valid
// Difficulty: Medium
// Tags     : String, Stack, Greedy, Bracket Sequences
// Link     : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8628000 (beats 54%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int minAddToMakeValid(char* s) {
    int open = 0;
    int add = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            open++;
        } else {
            if (open > 0) {
                open--;
            } else {
                add++;
            }
        }
    }

    return add + open;
}