// ──────────────────────────────────────────────────
// Problem  : 301. Remove Invalid Parentheses
// Difficulty: Hard
// Tags     : String, Backtracking, Breadth-First Search
// Link     : https://leetcode.com/problems/remove-invalid-parentheses/
// Runtime  : 33 ms (beats 53%)
// Memory   : 9368000 (beats 83%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isValid(const char *s) {
    int count = 0;
    while (*s) {
        if (*s == '(') {
            count++;
        } else if (*s == ')') {
            count--;
            if (count < 0) return 0;
        }
        s++;
    }
    return count == 0;
}

static void backtrack(const char *s, int index, int openRem, int closeRem, int count, char *path, int pathLen, char ***res, int *resSize, int *capacity) {
    if (count < 0) return;

    if (s[index] == '\0') {
        if (openRem == 0 && closeRem == 0 && count == 0) {
            path[pathLen] = '\0';
            for (int i = 0; i < *resSize; i++) {
                if (strcmp((*res)[i], path) == 0) return;
            }
            if (*resSize == *capacity) {
                *capacity *= 2;
                *res = (char **)realloc(*res, (*capacity) * sizeof(char *));
            }
            (*res)[*resSize] = (char *)malloc((pathLen + 1) * sizeof(char));
            strcpy((*res)[*resSize], path);
            (*resSize)++;
        }
        return;
    }

    char c = s[index];

    if (c == '(') {
        if (openRem > 0) {
            backtrack(s, index + 1, openRem - 1, closeRem, count, path, pathLen, res, resSize, capacity);
        }
        path[pathLen] = c;
        backtrack(s, index + 1, openRem, closeRem, count + 1, path, pathLen + 1, res, resSize, capacity);
    } else if (c == ')') {
        if (closeRem > 0) {
            backtrack(s, index + 1, openRem, closeRem - 1, count, path, pathLen, res, resSize, capacity);
        }
        path[pathLen] = c;
        backtrack(s, index + 1, openRem, closeRem, count - 1, path, pathLen + 1, res, resSize, capacity);
    } else {
        path[pathLen] = c;
        backtrack(s, index + 1, openRem, closeRem, count, path, pathLen + 1, res, resSize, capacity);
    }
}

char **removeInvalidParentheses(char *s, int *returnSize) {
    int openRem = 0, closeRem = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            openRem++;
        } else if (s[i] == ')') {
            if (openRem > 0) {
                openRem--;
            } else {
                closeRem++;
            }
        }
    }

    int capacity = 16;
    *returnSize = 0;
    char **res = (char **)malloc(capacity * sizeof(char *));
    char *path = (char *)malloc((strlen(s) + 1) * sizeof(char));

    backtrack(s, 0, openRem, closeRem, 0, path, 0, &res, returnSize, &capacity);

    free(path);
    return res;
}