// ──────────────────────────────────────────────────
// Problem  : 522. Longest Uncommon Subsequence II
// Difficulty: Medium
// Tags     : Array, Hash Table, Two Pointers, String, Sorting
// Link     : https://leetcode.com/problems/longest-uncommon-subsequence-ii/
// Runtime  : 3 ms (beats 8%)
// Memory   : 8880000 (beats 48%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <string.h>

bool isSubsequence(const char *s1, const char *s2) {
    int i = 0, j = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    while (i < len1 && j < len2) {
        if (s1[i] == s2[j]) {
            i++;
        }
        j++;
    }
    return i == len1;
}

int findLUSlength(char** strs, int strsSize) {
    int maxLength = -1;

    for (int i = 0; i < strsSize; i++) {
        bool isUncommon = true;
        
        for (int j = 0; j < strsSize; j++) {
            if (i != j && isSubsequence(strs[i], strs[j])) {
                isUncommon = false;
                break;
            }
        }

        if (isUncommon) {
            int len = strlen(strs[i]);
            if (len > maxLength) {
                maxLength = len;
            }
        }
    }

    return maxLength;
}