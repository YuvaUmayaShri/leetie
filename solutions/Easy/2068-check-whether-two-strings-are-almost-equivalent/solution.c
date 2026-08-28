// ──────────────────────────────────────────────────
// Problem  : 2068. Check Whether Two Strings are Almost Equivalent
// Difficulty: Easy
// Tags     : Hash Table, String, Counting
// Link     : https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8712000 (beats 33%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool checkAlmostEquivalent(char* word1, char* word2) {
    int count[26] = {0};

    for (int i = 0; word1[i] != '\0'; i++) {
        count[word1[i] - 'a']++;
        count[word2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (abs(count[i]) > 3) {
            return false;
        }
    }

    return true;
}