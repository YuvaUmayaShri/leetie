// ──────────────────────────────────────────────────
// Problem  : 856. Score of Parentheses
// Difficulty: Medium
// Tags     : String, Stack, Bracket Sequences
// Link     : https://leetcode.com/problems/score-of-parentheses/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8572000 (beats 68%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int scoreOfParentheses(char* s) {
    int score = 0;
    int depth = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            depth++;
        } else {
            depth--;
            if (s[i - 1] == '(') {
                score += 1 << depth;
            }
        }
    }
    
    return score;
}