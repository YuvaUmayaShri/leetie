// ──────────────────────────────────────────────────
// Problem  : 131. Palindrome Partitioning
// Difficulty: Medium
// Tags     : String, Dynamic Programming, Backtracking
// Link     : https://leetcode.com/problems/palindrome-partitioning/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8608000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void backtrack(char* s, int start, int len, char*** result, int* returnSize, int** returnColumnSizes, char** currentPartition, int currentSize) {
    if (start == len) {
        result[*returnSize] = (char**)malloc(sizeof(char*) * currentSize);
        (*returnColumnSizes)[*returnSize] = currentSize;
        for (int i = 0; i < currentSize; i++) {
            result[*returnSize][i] = strdup(currentPartition[i]);
        }
        (*returnSize)++;
        return;
    }

    for (int end = start; end < len; end++) {
        if (isPalindrome(s, start, end)) {
            int subLen = end - start + 1;
            char* subStr = (char*)malloc(sizeof(char) * (subLen + 1));
            strncpy(subStr, s + start, subLen);
            subStr[subLen] = '\0';

            currentPartition[currentSize] = subStr;
            backtrack(s, end + 1, len, result, returnSize, returnColumnSizes, currentPartition, currentSize + 1);
            free(subStr);
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int len = strlen(s);
    int maxCombinations = 1 << len;

    char*** result = (char***)malloc(sizeof(char**) * maxCombinations);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxCombinations);
    *returnSize = 0;

    char** currentPartition = (char**)malloc(sizeof(char*) * len);

    backtrack(s, 0, len, result, returnSize, returnColumnSizes, currentPartition, 0);

    free(currentPartition);
    return result;
}