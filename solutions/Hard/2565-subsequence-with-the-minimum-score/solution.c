// ──────────────────────────────────────────────────
// Problem  : 2565. Subsequence With the Minimum Score
// Difficulty: Hard
// Tags     : Two Pointers, String, Binary Search
// Link     : https://leetcode.com/problems/subsequence-with-the-minimum-score/
// Runtime  : 3 ms (beats 50%)
// Memory   : 12304000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumScore(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);

    int* left = (int*)malloc(tLen * sizeof(int));
    int* right = (int*)malloc(tLen * sizeof(int));

    for (int i = 0; i < tLen; i++) {
        left[i] = -1;
        right[i] = -1;
    }

    int p = 0;
    for (int i = 0; i < sLen && p < tLen; i++) {
        if (s[i] == t[p]) {
            left[p] = i;
            p++;
        }
    }

    if (p == tLen) {
        free(left);
        free(right);
        return 0;
    }

    p = tLen - 1;
    for (int i = sLen - 1; i >= 0 && p >= 0; i--) {
        if (s[i] == t[p]) {
            right[p] = i;
            p--;
        }
    }

    int ans = tLen;

    for (int i = 0; i < tLen; i++) {
        if (right[i] != -1) {
            ans = MIN(ans, i);
            break;
        }
    }

    for (int i = tLen - 1; i >= 0; i--) {
        if (left[i] != -1) {
            ans = MIN(ans, tLen - 1 - i);
            break;
        }
    }

    int j = 0;
    for (int i = 0; i < tLen; i++) {
        if (left[i] == -1) break;

        while (j < tLen && (right[j] == -1 || right[j] <= left[i])) {
            j++;
        }

        if (j < tLen) {
            ans = MIN(ans, j - i - 1);
        }
    }

    free(left);
    free(right);

    return ans;
}