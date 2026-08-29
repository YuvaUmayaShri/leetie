// ──────────────────────────────────────────────────
// Problem  : 224. Basic Calculator
// Difficulty: Hard
// Tags     : Math, String, Stack, Recursion
// Link     : https://leetcode.com/problems/basic-calculator/
// Runtime  : 0 ms (beats 100%)
// Memory   : 11288000 (beats 38%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <ctype.h>

int calculate(char* s) {
    int stack[300000];
    int top = -1;
    
    int result = 0;
    int sign = 1;
    int i = 0;

    while (s[i] != '\0') {
        char ch = s[i];

        if (isdigit(ch)) {
            long long val = 0;
            while (s[i] != '\0' && isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            result += sign * val;
            continue;
        } else if (ch == '+') {
            sign = 1;
        } else if (ch == '-') {
            sign = -1;
        } else if (ch == '(') {
            stack[++top] = result;
            stack[++top] = sign;
            result = 0;
            sign = 1;
        } else if (ch == ')') {
            int prevSign = stack[top--];
            int prevResult = stack[top--];
            result = prevResult + prevSign * result;
        }
        
        i++;
    }

    return result;
}