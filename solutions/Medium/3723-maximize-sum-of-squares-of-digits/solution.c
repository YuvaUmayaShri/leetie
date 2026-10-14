// ──────────────────────────────────────────────────
// Problem  : 3723. Maximize Sum of Squares of Digits
// Difficulty: Medium
// Tags     : Math, Greedy
// Link     : https://leetcode.com/problems/maximize-sum-of-squares-of-digits/
// Runtime  : 18 ms (beats 43%)
// Memory   : 33516000 (beats 64%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* maxSumOfSquares(int num, int sum) {
    if ((long long)num * 9 < sum) {
        char* res = (char*)malloc(1);
        res[0] = '\0';
        return res;
    }

    char* res = (char*)malloc(num + 1);
    res[num] = '\0';

    for (int i = 0; i < num; i++) {
        int val = sum < 9 ? sum : 9;
        res[i] = '0' + val;
        sum -= val;
    }

    return res;
}