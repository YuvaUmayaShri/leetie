// ──────────────────────────────────────────────────
// Problem  : 168. Excel Sheet Column Title
// Difficulty: Easy
// Tags     : Math, String
// Link     : https://leetcode.com/problems/excel-sheet-column-title/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8500000 (beats 61%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

char* convertToTitle(int columnNumber) {
    char temp[10];
    int i = 0;
    
    while (columnNumber > 0) {
        columnNumber--;
        temp[i++] = (columnNumber % 26) + 'A';
        columnNumber /= 26;
    }
    
    char* result = (char*)malloc((i + 1) * sizeof(char));
    for (int j = 0; j < i; j++) {
        result[j] = temp[i - 1 - j];
    }
    result[i] = '\0';
    
    return result;
}