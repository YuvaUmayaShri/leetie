// ──────────────────────────────────────────────────
// Problem  : 3031. Minimum Time to Revert Word to Initial State II
// Difficulty: Hard
// Tags     : String, Rolling Hash, String Matching, Hash Function
// Link     : https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-ii/
// Runtime  : 64 ms (beats 0%)
// Memory   : 40844000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumTimeToInitialState(char* word, int k) {
    int n = strlen(word);
    int* z = (int*)calloc(n, sizeof(int));
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            int k_idx = i - l;
            z[i] = (r - i + 1 < z[k_idx]) ? (r - i + 1) : z[k_idx];
        }
        while (i + z[i] < n && word[z[i]] == word[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    for (int i = k; i < n; i += k) {
        if (z[i] >= n - i) {
            free(z);
            return i / k;
        }
    }

    free(z);
    return (n + k - 1) / k;
}