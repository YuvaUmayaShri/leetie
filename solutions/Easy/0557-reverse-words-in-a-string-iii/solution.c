// ──────────────────────────────────────────────────
// Problem  : 557. Reverse Words in a String III
// Difficulty: Easy
// Tags     : Two Pointers, String
// Link     : https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9876000 (beats 83%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

void reverse(char* s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

char* reverseWords(char* s) {
    int start = 0;
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == ' ') {
            reverse(s, start, i - 1);
            start = i + 1;
        }
        i++;
    }

    reverse(s, start, i - 1);

    return s;
}