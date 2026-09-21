// ──────────────────────────────────────────────────
// Problem  : 1876. Substrings of Size Three with Distinct Characters
// Difficulty: Easy
// Tags     : Hash Table, String, Sliding Window, Counting
// Link     : https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8536000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <string.h>

int countGoodSubstrings(char* s) {
    int len = strlen(s);
    if (len < 3) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i <= len - 3; i++) {
        if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
            count++;
        }
    }

    return count;
}