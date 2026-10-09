// ──────────────────────────────────────────────────
// Problem  : 1541. Minimum Insertions to Balance a Parentheses String
// Difficulty: Medium
// Tags     : String, Stack, Greedy, Bracket Sequences
// Link     : https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
// Runtime  : 1 ms (beats 88%)
// Memory   : 10728000 (beats 6%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int minInsertions(char *s) {
    int insertions = 0;
    int right_needed = 0;

    while (*s != '\0') {
        if (*s == '(') {
            if (right_needed % 2 != 0) {
                insertions++;
                right_needed--;
            }

            right_needed += 2;
        } else {
            right_needed--;

            if (right_needed < 0) {
                insertions++;
                right_needed += 2;
            }
        }

        s++;
    }

    return insertions + right_needed;
}