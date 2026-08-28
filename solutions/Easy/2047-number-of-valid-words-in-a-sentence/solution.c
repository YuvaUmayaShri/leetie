// ──────────────────────────────────────────────────
// Problem  : 2047. Number of Valid Words in a Sentence
// Difficulty: Easy
// Tags     : String
// Link     : https://leetcode.com/problems/number-of-valid-words-in-a-sentence/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8984000 (beats 91%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool isValid(char* s, int start, int end) {
    int hyphenCount = 0;
    int len = end - start;

    for (int i = start; i < end; i++) {
        char ch = s[i];
        
        if (ch >= '0' && ch <= '9') {
            return false;
        }
        
        if (ch == '-' ) {
            hyphenCount++;
            if (hyphenCount > 1) {
                return false;
            }
            if (i == start || i == end - 1) {
                return false;
            }
            if (!(s[i - 1] >= 'a' && s[i - 1] <= 'z') || !(s[i + 1] >= 'a' && s[i + 1] <= 'z')) {
                return false;
            }
        }
        
        if (ch == '!' || ch == '.' || ch == ',') {
            if (i != end - 1) {
                return false;
            }
        }
    }
    
    return true;
}

int countValidWords(char* sentence) {
    int count = 0;
    int n = strlen(sentence);
    int i = 0;

    while (i < n) {
        while (i < n && sentence[i] == ' ') {
            i++;
        }
        if (i >= n) {
            break;
        }
        
        int start = i;
        while (i < n && sentence[i] != ' ') {
            i++;
        }
        int end = i;

        if (isValid(sentence, start, end)) {
            count++;
        }
    }

    return count;
}