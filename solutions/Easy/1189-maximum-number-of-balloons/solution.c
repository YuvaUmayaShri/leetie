// ──────────────────────────────────────────────────
// Problem  : 1189. Maximum Number of Balloons
// Difficulty: Easy
// Tags     : Hash Table, String, Counting
// Link     : https://leetcode.com/problems/maximum-number-of-balloons/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8540000 (beats 84%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int maxNumberOfBalloons(char* text) {
    int count[26] = {0};
    
    for (int i = 0; text[i] != '\0'; i++) {
        count[text[i] - 'a']++;
    }

    int b = count['b' - 'a'];
    int a = count['a' - 'a'];
    int l = count['l' - 'a'] / 2;
    int o = count['o' - 'a'] / 2;
    int n = count['n' - 'a'];

    int min = b;
    if (a < min) min = a;
    if (l < min) min = l;
    if (o < min) min = o;
    if (n < min) min = n;

    return min;
}