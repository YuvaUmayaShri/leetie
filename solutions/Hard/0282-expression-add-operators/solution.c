// ──────────────────────────────────────────────────
// Problem  : 282. Expression Add Operators
// Difficulty: Hard
// Tags     : Math, String, Backtracking
// Link     : https://leetcode.com/problems/expression-add-operators/
// Runtime  : 29 ms (beats 81%)
// Memory   : 15232000 (beats 81%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

void backtrack(char* num, int target, int index, long eval, long prevNum, 
               char* expr, int exprLen, char*** result, int* capacity, int* returnSize) {
    if (num[index] == '\0') {
        if (eval == target) {
            if (*returnSize == *capacity) {
                *capacity *= 2;
                *result = (char**)realloc(*result, (*capacity) * sizeof(char*));
            }
            char* validExpr = (char*)malloc((exprLen + 1) * sizeof(char));
            memcpy(validExpr, expr, exprLen);
            validExpr[exprLen] = '\0';
            (*result)[*returnSize] = validExpr;
            (*returnSize)++;
        }
        return;
    }

    long currNum = 0;
    int startLen = exprLen;

    for (int i = index; num[i] != '\0'; i++) {
        // Avoid leading zeros in multi-digit numbers
        if (i > index && num[index] == '0') break;

        currNum = currNum * 10 + (num[i] - '0');
        int len = i - index + 1;

        if (index == 0) {
            // First number, no operator prefix
            memcpy(expr + exprLen, num + index, len);
            backtrack(num, target, i + 1, currNum, currNum, expr, exprLen + len, result, capacity, returnSize);
        } else {
            // Addition
            expr[exprLen] = '+';
            memcpy(expr + exprLen + 1, num + index, len);
            backtrack(num, target, i + 1, eval + currNum, currNum, expr, exprLen + 1 + len, result, capacity, returnSize);

            // Subtraction
            expr[exprLen] = '-';
            memcpy(expr + exprLen + 1, num + index, len);
            backtrack(num, target, i + 1, eval - currNum, -currNum, expr, exprLen + 1 + len, result, capacity, returnSize);

            // Multiplication
            expr[exprLen] = '*';
            memcpy(expr + exprLen + 1, num + index, len);
            backtrack(num, target, i + 1, eval - prevNum + (prevNum * currNum), prevNum * currNum, expr, exprLen + 1 + len, result, capacity, returnSize);
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** addOperators(char* num, int target, int* returnSize) {
    *returnSize = 0;
    int len = strlen(num);
    if (len == 0) return NULL;

    int capacity = 1000;
    char** result = (char**)malloc(capacity * sizeof(char*));
    char* expr = (char*)malloc((2 * len + 1) * sizeof(char));

    backtrack(num, target, 0, 0, 0, expr, 0, &result, &capacity, returnSize);

    free(expr);
    return result;
}