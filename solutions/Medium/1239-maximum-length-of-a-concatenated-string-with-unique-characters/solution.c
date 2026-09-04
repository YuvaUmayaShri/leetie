// ──────────────────────────────────────────────────
// Problem  : 1239. Maximum Length of a Concatenated String with Unique Characters
// Difficulty: Medium
// Tags     : Array, String, Backtracking, Bit Manipulation
// Link     : https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8456000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

void backtrack(char** arr, int arrSize, int index, int currentMask, int currentLen, int* maxLen) {
    *maxLen = max(*maxLen, currentLen);

    for (int i = index; i < arrSize; i++) {
        int wordMask = 0;
        int duplicate = 0;

        for (int j = 0; arr[i][j] != '\0'; j++) {
            int bit = 1 << (arr[i][j] - 'a');
            if (wordMask & bit) {
                duplicate = 1;
                break;
            }
            wordMask |= bit;
        }

        if (duplicate || (currentMask & wordMask)) {
            continue;
        }

        backtrack(arr, arrSize, i + 1, currentMask | wordMask, currentLen + strlen(arr[i]), maxLen);
    }
}

int maxLength(char** arr, int arrSize) {
    int maxLen = 0;
    backtrack(arr, arrSize, 0, 0, 0, &maxLen);
    return maxLen;
}