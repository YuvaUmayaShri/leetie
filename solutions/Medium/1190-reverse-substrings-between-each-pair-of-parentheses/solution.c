// ──────────────────────────────────────────────────
// Problem  : 1190. Reverse Substrings Between Each Pair of Parentheses
// Difficulty: Medium
// Tags     : String, Stack, Bracket Sequences
// Link     : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9140000 (beats 15%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseParentheses(char* s) {
    int len = strlen(s);
    int stack[2000];
    int top = -1;
    int pair[2000];

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else if (s[i] == ')') {
            int j = stack[top--];
            pair[i] = j;
            pair[j] = i;
        }
    }

    char* res = (char*)malloc((len + 1) * sizeof(char));
    int resIdx = 0;
    int curr = 0;
    int direction = 1;

    while (curr < len) {
        if (s[curr] == '(' || s[curr] == ')') {
            curr = pair[curr];
            direction = -direction;
        } else {
            res[resIdx++] = s[curr];
        }
        curr += direction;
    }

    res[resIdx] = '\0';
    return res;
}