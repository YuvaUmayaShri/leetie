// ──────────────────────────────────────────────────
// Problem  : 1170. Compare Strings by Frequency of the Smallest Character
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Binary Search, Sorting
// Link     : https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12752000 (beats 86%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

int f(const char* s) {
    char minChar = 'z' + 1;
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] < minChar) {
            minChar = s[i];
            count = 1;
        } else if (s[i] == minChar) {
            count++;
        }
    }
    return count;
}

int* numSmallerByFrequency(char** queries, int queriesSize, char** words, int wordsSize, int* returnSize) {
    int wordsFreq[11] = {0};
    for (int i = 0; i < wordsSize; i++) {
        int freq = f(words[i]);
        wordsFreq[freq]++;
    }

    int suffixSum[12] = {0};
    for (int i = 10; i >= 1; i--) {
        suffixSum[i] = suffixSum[i + 1] + wordsFreq[i];
    }

    int* result = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        int qFreq = f(queries[i]);
        result[i] = suffixSum[qFreq + 1];
    }

    return result;
}