// ──────────────────────────────────────────────────
// Problem  : 682. Baseball Game
// Difficulty: Easy
// Tags     : Array, Stack, Simulation
// Link     : https://leetcode.com/problems/baseball-game/
// Runtime  : N/A (beats 0%)
// Memory   : N/A (beats 0%)
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