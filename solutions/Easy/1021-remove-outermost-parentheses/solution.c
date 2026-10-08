// ──────────────────────────────────────────────────
// Problem  : 1021. Remove Outermost Parentheses
// Difficulty: Easy
// Tags     : String, Stack, Bracket Sequences
// Link     : https://leetcode.com/problems/remove-outermost-parentheses/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8812000 (beats 60%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

char* removeOuterParentheses(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int count = 0;
    int idx = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            // Include '(' only if it's not the outermost opening parenthesis
            if (count > 0) {
                result[idx++] = s[i];
            }
            count++;
        } else {
            count--;
            // Include ')' only if it's not the outermost closing parenthesis
            if (count > 0) {
                result[idx++] = s[i];
            }
        }
    }

    result[idx] = '\0';
    return result;
}