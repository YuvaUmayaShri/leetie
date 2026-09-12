// ──────────────────────────────────────────────────
// Problem  : 241. Different Ways to Add Parentheses
// Difficulty: Medium
// Tags     : Math, String, Dynamic Programming, Recursion, Memoization, Bracket Sequences
// Link     : https://leetcode.com/problems/different-ways-to-add-parentheses/
// Runtime  : 0 ms (beats 0%)
// Memory   : 9304000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int* diffWaysToCompute(char* expression, int* returnSize) {
    int len = strlen(expression);
    int* results = (int*)malloc(10000 * sizeof(int));
    int count = 0;

    for (int i = 0; i < len; i++) {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*') {
            char left[30];
            char right[30];

            strncpy(left, expression, i);
            left[i] = '\0';
            strcpy(right, expression + i + 1);

            int leftSize = 0;
            int rightSize = 0;

            int* leftResults = diffWaysToCompute(left, &leftSize);
            int* rightResults = diffWaysToCompute(right, &rightSize);

            for (int l = 0; l < leftSize; l++) {
                for (int r = 0; r < rightSize; r++) {
                    if (c == '+') {
                        results[count++] = leftResults[l] + rightResults[r];
                    } else if (c == '-') {
                        results[count++] = leftResults[l] - rightResults[r];
                    } else if (c == '*') {
                        results[count++] = leftResults[l] * rightResults[r];
                    }
                }
            }

            free(leftResults);
            free(rightResults);
        }
    }

    if (count == 0) {
        results[0] = atoi(expression);
        *returnSize = 1;
        return results;
    }

    *returnSize = count;
    return results;
}