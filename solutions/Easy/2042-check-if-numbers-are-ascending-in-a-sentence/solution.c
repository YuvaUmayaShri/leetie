// ──────────────────────────────────────────────────
// Problem  : 2042. Check if Numbers Are Ascending in a Sentence
// Difficulty: Easy
// Tags     : String
// Link     : https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8424000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool areNumbersAscending(char* s) {
    int prev = -1;
    int curr = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            curr = curr * 10 + (s[i] - '0');
        } else if (i > 0 && s[i - 1] >= '0' && s[i - 1] <= '9') {
            if (curr <= prev) {
                return false;
            }
            prev = curr;
            curr = 0;
        }
    }
    
    if (s[strlen(s) - 1] >= '0' && s[strlen(s) - 1] <= '9') {
        if (curr <= prev) {
            return false;
        }
    }
    
    return true;
}