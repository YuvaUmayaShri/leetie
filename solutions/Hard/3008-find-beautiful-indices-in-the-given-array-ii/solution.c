// ──────────────────────────────────────────────────
// Problem  : 3008. Find Beautiful Indices in the Given Array II
// Difficulty: Hard
// Tags     : Two Pointers, String, Binary Search, Rolling Hash, String Matching, Hash Function, Z Algorithm, Knuth–Morris–Pratt Algorithm, Boyer–Moore String-Search Algorithm
// Link     : https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-ii/
// Runtime  : 3 ms (beats 0%)
// Memory   : 8552000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPSArray(char* pat, int M, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpSearch(char* pat, char* txt, int* indices, int* count) {
    int M = strlen(pat);
    int N = strlen(txt);
    int* lps = (int*)malloc(sizeof(int) * M);
    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    *count = 0;

    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            indices[(*count)++] = i - j;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    free(lps);
}

int* beautifulIndices(char* s, char* a, char* b, int k, int* returnSize) {
    int n = strlen(s);
    int* posA = (int*)malloc(sizeof(int) * n);
    int* posB = (int*)malloc(sizeof(int) * n);
    int countA = 0, countB = 0;

    kmpSearch(a, s, posA, &countA);
    kmpSearch(b, s, posB, &countB);

    int* result = (int*)malloc(sizeof(int) * countA);
    *returnSize = 0;

    int j = 0;
    for (int i = 0; i < countA; i++) {
        while (j < countB && posB[j] < posA[i] - k) {
            j++;
        }
        if (j < countB && posB[j] <= posA[i] + k) {
            result[(*returnSize)++] = posA[i];
        }
    }

    free(posA);
    free(posB);
    return result;
}