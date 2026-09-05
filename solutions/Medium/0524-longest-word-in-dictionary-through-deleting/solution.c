// ──────────────────────────────────────────────────
// Problem  : 524. Longest Word in Dictionary through Deleting
// Difficulty: Medium
// Tags     : Array, Two Pointers, String, Sorting
// Link     : https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
// Runtime  : 7 ms (beats 78%)
// Memory   : 12984000 (beats 90%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <string.h>
#include <stdbool.h>

bool isSubsequence(const char* word, const char* s) {
    while (*word && *s) {
        if (*word == *s) {
            word++;
        }
        s++;
    }
    return *word == '\0';
}

char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    char* result = "";
    
    for (int i = 0; i < dictionarySize; i++) {
        char* word = dictionary[i];
        int wordLen = strlen(word);
        int resLen = strlen(result);
        
        if (wordLen > resLen || (wordLen == resLen && strcmp(word, result) < 0)) {
            if (isSubsequence(word, s)) {
                result = word;
            }
        }
    }
    
    return result;
}