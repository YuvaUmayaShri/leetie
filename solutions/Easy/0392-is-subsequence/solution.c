// ──────────────────────────────────────────────────
// Problem  : 392. Is Subsequence
// Difficulty: Easy
// Tags     : Two Pointers, String, Dynamic Programming
// Link     : https://leetcode.com/problems/is-subsequence/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8732000 (beats 5%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool isSubsequence(char* s, char* t) {
    while (*s && *t) {
        if (*s == *t) {
            s++;
        }
        t++;
    }
    return *s == '\0';
}