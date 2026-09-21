// ──────────────────────────────────────────────────
// Problem  : 567. Permutation in String
// Difficulty: Medium
// Tags     : Hash Table, Two Pointers, String, Sliding Window
// Link     : https://leetcode.com/problems/permutation-in-string/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9108000 (beats 31%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <string.h>

bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 > len2) {
        return false;
    }

    int count1[26] = {0};
    int count2[26] = {0};

    for (int i = 0; i < len1; i++) {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }

    int matches = 0;
    for (int i = 0; i < 26; i++) {
        if (count1[i] == count2[i]) {
            matches++;
        }
    }

    for (int i = 0; i < len2 - len1; i++) {
        if (matches == 26) {
            return true;
        }

        int r = s2[i + len1] - 'a';
        int l = s2[i] - 'a';

        count2[r]++;
        if (count2[r] == count1[r]) {
            matches++;
        } else if (count2[r] == count1[r] + 1) {
            matches--;
        }

        count2[l]--;
        if (count2[l] == count1[l]) {
            matches++;
        } else if (count2[l] == count1[l] - 1) {
            matches--;
        }
    }

    return matches == 26;
}