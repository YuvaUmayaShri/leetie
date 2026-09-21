// ──────────────────────────────────────────────────
// Problem  : 187. Repeated DNA Sequences
// Difficulty: Medium
// Tags     : Hash Table, String, Bit Manipulation, Sliding Window, Rolling Hash, Hash Function, Z Algorithm, Boyer–Moore String-Search Algorithm
// Link     : https://leetcode.com/problems/repeated-dna-sequences/
// Runtime  : 163 ms (beats 40%)
// Memory   : 277504000 (beats 21%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** findRepeatedDnaSequences(char* s, int* returnSize) {
    int len = strlen(s);
    if (len < 10) {
        *returnSize = 0;
        return NULL;
    }

    char* seen = (char*)calloc(1 << 20, sizeof(char));
    char** result = (char**)malloc(len * sizeof(char*));
    *returnSize = 0;

    int mask = (1 << 20) - 1;
    int curr = 0;

    for (int i = 0; i < len; i++) {
        int val = 0;
        switch (s[i]) {
            case 'A': val = 0; break;
            case 'C': val = 1; break;
            case 'G': val = 2; break;
            case 'T': val = 3; break;
        }

        curr = ((curr << 2) | val) & mask;

        if (i >= 9) {
            if (seen[curr] == 1) {
                result[*returnSize] = (char*)malloc(11 * sizeof(char));
                strncpy(result[*returnSize], s + i - 9, 10);
                result[*returnSize][10] = '\0';
                (*returnSize)++;
                seen[curr] = 2;
            } else if (seen[curr] == 0) {
                seen[curr] = 1;
            }
        }
    }

    free(seen);
    return result;
}