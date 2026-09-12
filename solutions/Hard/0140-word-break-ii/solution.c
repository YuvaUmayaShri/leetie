// ──────────────────────────────────────────────────
// Problem  : 140. Word Break II
// Difficulty: Hard
// Tags     : Array, Hash Table, String, Dynamic Programming, Backtracking, Trie, Memoization
// Link     : https://leetcode.com/problems/word-break-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8760000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char* s, int start, int len, char** wordDict, int wordDictSize, char*** result, int* returnSize, char* currentSentence, int currentLen) {
    if (start == len) {
        (*result)[*returnSize] = (char*)malloc((currentLen + 1) * sizeof(char));
        strncpy((*result)[*returnSize], currentSentence, currentLen - 1);
        (*result)[*returnSize][currentLen - 1] = '\0';
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < wordDictSize; i++) {
        int wordLen = strlen(wordDict[i]);
        if (start + wordLen <= len && strncmp(s + start, wordDict[i], wordLen) == 0) {
            int prevLen = currentLen;

            strcpy(currentSentence + currentLen, wordDict[i]);
            currentLen += wordLen;
            currentSentence[currentLen++] = ' ';

            backtrack(s, start + wordLen, len, wordDict, wordDictSize, result, returnSize, currentSentence, currentLen);

            currentLen = prevLen;
        }
    }
}

char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    int len = strlen(s);

    bool* dp = (bool*)calloc(len + 1, sizeof(bool));
    dp[0] = true;

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < wordDictSize; j++) {
            int wordLen = strlen(wordDict[j]);
            if (i >= wordLen && dp[i - wordLen] && strncmp(s + i - wordLen, wordDict[j], wordLen) == 0) {
                dp[i] = true;
                break;
            }
        }
    }

    *returnSize = 0;
    if (!dp[len]) {
        free(dp);
        return NULL;
    }

    free(dp);

    char** result = (char**)malloc(10000 * sizeof(char*));
    char* currentSentence = (char*)malloc(500 * sizeof(char));

    backtrack(s, 0, len, wordDict, wordDictSize, &result, returnSize, currentSentence, 0);

    free(currentSentence);
    return result;
}