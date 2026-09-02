// ──────────────────────────────────────────────────
// Problem  : 87. Scramble String
// Difficulty: Hard
// Tags     : String, Dynamic Programming
// Link     : https://leetcode.com/problems/scramble-string/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9576000 (beats 85%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <string.h>

static char memo[31][31][31];

static bool solve(char* s1, int i1, char* s2, int i2, int len) {
    if (memo[i1][i2][len] != 0) {
        return memo[i1][i2][len] == 1;
    }

    if (strncmp(s1 + i1, s2 + i2, len) == 0) {
        memo[i1][i2][len] = 1;
        return true;
    }

    int count[26] = {0};
    for (int k = 0; k < len; k++) {
        count[s1[i1 + k] - 'a']++;
        count[s2[i2 + k] - 'a']--;
    }
    for (int k = 0; k < 26; k++) {
        if (count[k] != 0) {
            memo[i1][i2][len] = -1;
            return false;
        }
    }

    for (int k = 1; k < len; k++) {
        if (solve(s1, i1, s2, i2, k) && solve(s1, i1 + k, s2, i2 + k, len - k)) {
            memo[i1][i2][len] = 1;
            return true;
        }
        if (solve(s1, i1, s2, i2 + len - k, k) && solve(s1, i1 + k, s2, i2, len - k)) {
            memo[i1][i2][len] = 1;
            return true;
        }
    }

    memo[i1][i2][len] = -1;
    return false;
}

bool isScramble(char* s1, char* s2) {
    int n = strlen(s1);
    memset(memo, 0, sizeof(memo));
    return solve(s1, 0, s2, 0, n);
}