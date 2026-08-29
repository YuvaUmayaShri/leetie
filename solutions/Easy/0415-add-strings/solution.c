// ──────────────────────────────────────────────────
// Problem  : 415. Add Strings
// Difficulty: Easy
// Tags     : Math, String, Simulation
// Link     : https://leetcode.com/problems/add-strings/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8652000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 > len2 ? len1 : len2;
    
    char* res = (char*)malloc(sizeof(char) * (maxLen + 2));
    res[maxLen + 1] = '\0';
    
    int i = len1 - 1;
    int j = len2 - 1;
    int k = maxLen;
    int carry = 0;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int d1 = (i >= 0) ? num1[i--] - '0' : 0;
        int d2 = (j >= 0) ? num2[j--] - '0' : 0;
        
        int sum = d1 + d2 + carry;
        res[k--] = (sum % 10) + '0';
        carry = sum / 10;
    }
    
    return res + k + 1;
}