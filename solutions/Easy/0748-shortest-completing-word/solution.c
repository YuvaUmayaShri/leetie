// ──────────────────────────────────────────────────
// Problem  : 748. Shortest Completing Word
// Difficulty: Easy
// Tags     : Array, Hash Table, String
// Link     : https://leetcode.com/problems/shortest-completing-word/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9664000 (beats 40%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int target[26] = {0};
    
    for (int i = 0; licensePlate[i] != '\0'; i++) {
        char c = licensePlate[i];
        if (c >= 'a' && c <= 'z') {
            target[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            target[c - 'A']++;
        }
    }
    
    char* result = NULL;
    int min_len = 10000;
    
    for (int i = 0; i < wordsSize; i++) {
        int word_count[26] = {0};
        int len = 0;
        
        for (int j = 0; words[i][j] != '\0'; j++) {
            word_count[words[i][j] - 'a']++;
            len++;
        }
        
        if (len >= min_len) continue;
        
        int valid = 1;
        for (int k = 0; k < 26; k++) {
            if (word_count[k] < target[k]) {
                valid = 0;
                break;
            }
        }
        
        if (valid) {
            min_len = len;
            result = words[i];
        }
    }
    
    return result;
}