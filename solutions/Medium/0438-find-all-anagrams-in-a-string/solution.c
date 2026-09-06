// ──────────────────────────────────────────────────
// Problem  : 438. Find All Anagrams in a String
// Difficulty: Medium
// Tags     : Hash Table, String, Sliding Window
// Link     : https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Runtime  : 0 ms (beats 100%)
// Memory   : 14844000 (beats 28%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int* findAnagrams(char* s, char* p, int* returnSize) {
    int sLen = strlen(s);
    int pLen = strlen(p);

    if (sLen < pLen) {
        *returnSize = 0;
        return NULL;
    }

    int pCount[26] = {0};
    int sCount[26] = {0};

    for (int i = 0; i < pLen; i++) {
        pCount[p[i] - 'a']++;
        sCount[s[i] - 'a']++;
    }

    int* result = (int*)malloc(sLen * sizeof(int));
    int count = 0;

    for (int i = 0; i <= sLen - pLen; i++) {
        if (i > 0) {
            sCount[s[i - 1] - 'a']--;
            sCount[s[i + pLen - 1] - 'a']++;
        }

        int matches = 1;
        for (int j = 0; j < 26; j++) {
            if (pCount[j] != sCount[j]) {
                matches = 0;
                break;
            }
        }

        if (matches) {
            result[count++] = i;
        }
    }

    *returnSize = count;
    return result;
}