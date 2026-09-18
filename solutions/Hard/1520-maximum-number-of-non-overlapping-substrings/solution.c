// ──────────────────────────────────────────────────
// Problem  : 1520. Maximum Number of Non-Overlapping Substrings
// Difficulty: Hard
// Tags     : Hash Table, String, Greedy, Sorting
// Link     : https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
// Runtime  : 7 ms (beats 100%)
// Memory   : 17944000 (beats 38%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkValidRange(char* s, int i, int* l, int* r) {
    int right = r[s[i] - 'a'];
    for (int j = i; j <= right; ++j) {
        if (l[s[j] - 'a'] < i) return -1;
        if (r[s[j] - 'a'] > right) right = r[s[j] - 'a'];
    }
    return right;
}

char** maxNumOfSubstrings(char* s, int* returnSize) {
    int len = strlen(s);
    int l[26], r[26];
    for (int i = 0; i < 26; ++i) {
        l[i] = -1;
        r[i] = -1;
    }
    for (int i = 0; i < len; ++i) {
        if (l[s[i] - 'a'] == -1) l[s[i] - 'a'] = i;
        r[s[i] - 'a'] = i;
    }

    char** result = (char**)malloc(26 * sizeof(char*));
    *returnSize = 0;
    int lastEnd = -1;

    for (int i = 0; i < len; ++i) {
        if (i == l[s[i] - 'a']) {
            int newEnd = checkValidRange(s, i, l, r);
            if (newEnd != -1) {
                if (i > lastEnd) {
                    (*returnSize)++;
                }
                lastEnd = newEnd;
                int subLen = lastEnd - i + 1;
                result[*returnSize - 1] = (char*)malloc((subLen + 1) * sizeof(char));
                strncpy(result[*returnSize - 1], s + i, subLen);
                result[*returnSize - 1][subLen] = '\0';
            }
        }
    }
    return result;
}