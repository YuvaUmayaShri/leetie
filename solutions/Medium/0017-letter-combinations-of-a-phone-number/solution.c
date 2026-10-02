// ──────────────────────────────────────────────────
// Problem  : 17. Letter Combinations of a Phone Number
// Difficulty: Medium
// Tags     : Hash Table, String, Backtracking
// Link     : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9080000 (beats 57%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* PHONE_MAP[] = {
    "",     "",     "abc",  "def", 
    "ghi",  "jkl",  "mno", 
    "pqrs", "tuv",  "wxyz"
};

void backtrack(char* digits, int index, char* current, char** result, int* returnSize) {
    if (digits[index] == '\0') {
        result[*returnSize] = (char*)malloc((index + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    const char* letters = PHONE_MAP[digits[index] - '0'];
    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        current[index + 1] = '\0';
        backtrack(digits, index + 1, current, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int len = strlen(digits);
    if (len == 0) {
        return NULL;
    }

    int maxCombinations = 1;
    for (int i = 0; i < len; i++) {
        int digit = digits[i] - '0';
        if (digit == 7 || digit == 9) {
            maxCombinations *= 4;
        } else {
            maxCombinations *= 3;
        }
    }

    char** result = (char**)malloc(maxCombinations * sizeof(char*));
    char* current = (char*)malloc((len + 1) * sizeof(char));

    backtrack(digits, 0, current, result, returnSize);

    free(current);
    return result;
}