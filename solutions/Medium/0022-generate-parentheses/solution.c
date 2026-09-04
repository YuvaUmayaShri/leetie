// ──────────────────────────────────────────────────
// Problem  : 22. Generate Parentheses
// Difficulty: Medium
// Tags     : String, Dynamic Programming, Backtracking, Bracket Sequences
// Link     : https://leetcode.com/problems/generate-parentheses/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10052000 (beats 50%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

void backtrack(int n, int openCount, int closeCount, char* current, int length, char** result, int* returnSize) {
    if (length == 2 * n) {
        current[length] = '\0';
        result[*returnSize] = (char*)malloc((2 * n + 1) * sizeof(char));
        for (int i = 0; i <= 2 * n; i++) {
            result[*returnSize][i] = current[i];
        }
        (*returnSize)++;
        return;
    }

    if (openCount < n) {
        current[length] = '(';
        backtrack(n, openCount + 1, closeCount, current, length + 1, result, returnSize);
    }

    if (closeCount < openCount) {
        current[length] = ')';
        backtrack(n, openCount, closeCount + 1, current, length + 1, result, returnSize);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    char** result = (char**)malloc(5000 * sizeof(char*));
    char* current = (char*)malloc((2 * n + 1) * sizeof(char));

    backtrack(n, 0, 0, current, 0, result, returnSize);

    free(current);
    return result;
}