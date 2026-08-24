// ──────────────────────────────────────────────────
// Problem  : 828. Count Unique Characters of All Substrings of a Given String
// Difficulty: Hard
// Tags     : Hash Table, String, Dynamic Programming
// Link     : https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8492000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int uniqueLetterString(char* s) {
    int n = strlen(s);
    int last[26];
    int prev[26];
    
    for (int i = 0; i < 26; i++) {
        last[i] = -1;
        prev[i] = -1;
    }
    
    long long total = 0;
    
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'A';
        total += (long long)(i - last[c]) * (last[c] - prev[c]);
        prev[c] = last[c];
        last[c] = i;
    }
    
    for (int c = 0; c < 26; c++) {
        total += (long long)(n - last[c]) * (last[c] - prev[c]);
    }
    
    return (int)total;
}