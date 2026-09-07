// ──────────────────────────────────────────────────
// Problem  : 91. Decode Ways
// Difficulty: Medium
// Tags     : String, Dynamic Programming
// Link     : https://leetcode.com/problems/decode-ways/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8680000 (beats 71%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <string.h>

int numDecodings(char* s) {
    if (s == NULL || s[0] == '0') {
        return 0;
    }
    
    int n = strlen(s);
    int prev2 = 1;
    int prev1 = 1;
    
    for (int i = 1; i < n; i++) {
        int current = 0;
        int single_digit = s[i] - '0';
        int double_digit = (s[i - 1] - '0') * 10 + single_digit;
        
        if (single_digit >= 1 && single_digit <= 9) {
            current += prev1;
        }
        
        if (double_digit >= 10 && double_digit <= 26) {
            current += prev2;
        }
        
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}