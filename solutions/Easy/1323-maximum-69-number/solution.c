// ──────────────────────────────────────────────────
// Problem  : 1323. Maximum 69 Number
// Difficulty: Easy
// Tags     : Math, Greedy
// Link     : https://leetcode.com/problems/maximum-69-number/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8608000 (beats 41%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <string.h>

int maximum69Number(int num) {
    char str[6];
    sprintf(str, "%d", num);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '6') {
            str[i] = '9';
            break;
        }
    }

    int result;
    sscanf(str, "%d", &result);
    return result;
}