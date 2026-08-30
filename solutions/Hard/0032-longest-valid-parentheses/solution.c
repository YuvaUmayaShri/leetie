// ──────────────────────────────────────────────────
// Problem  : 32. Longest Valid Parentheses
// Difficulty: Hard
// Tags     : String, Dynamic Programming, Stack, Bracket Sequences
// Link     : https://leetcode.com/problems/longest-valid-parentheses/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10268000 (beats 38%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestValidParentheses(char *s) {
    int len = strlen(s);
    if (len == 0) return 0;

    int *stack = (int *)malloc((len + 1) * sizeof(int));
    int top = -1;
    int maxLen = 0;

    stack[++top] = -1;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top == -1) {
                stack[++top] = i;
            } else {
                maxLen = MAX(maxLen, i - stack[top]);
            }
        }
    }

    free(stack);
    return maxLen;
}