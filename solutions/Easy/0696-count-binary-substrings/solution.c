// ──────────────────────────────────────────────────
// Problem  : 696. Count Binary Substrings
// Difficulty: Easy
// Tags     : Two Pointers, String
// Link     : https://leetcode.com/problems/count-binary-substrings/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8488000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <string.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int countBinarySubstrings(char* s) {
    int prev = 0;
    int curr = 1;
    int count = 0;

    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == s[i - 1]) {
            curr++;
        } else {
            count += min(prev, curr);
            prev = curr;
            curr = 1;
        }
    }

    count += min(prev, curr);
    return count;
}