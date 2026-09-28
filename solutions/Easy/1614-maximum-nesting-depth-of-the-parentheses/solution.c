// ──────────────────────────────────────────────────
// Problem  : 1614. Maximum Nesting Depth of the Parentheses
// Difficulty: Easy
// Tags     : String, Stack, Bracket Sequences
// Link     : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8424000 (beats 94%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int maxDepth(char* s) {
    int max_depth = 0;
    int current_depth = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            current_depth++;
            if (current_depth > max_depth) {
                max_depth = current_depth;
            }
        } else if (s[i] == ')') {
            current_depth--;
        }
    }

    return max_depth;
}