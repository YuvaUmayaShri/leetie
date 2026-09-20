// ──────────────────────────────────────────────────
// Problem  : 3602. Hexadecimal and Hexatrigesimal Conversion
// Difficulty: Easy
// Tags     : Math, String
// Link     : https://leetcode.com/problems/hexadecimal-and-hexatrigesimal-conversion/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9180000 (beats 29%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toBase(long long val, int base, char* buffer) {
    char temp[64];
    int idx = 0;
    
    if (val == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }
    
    while (val > 0) {
        int rem = val % base;
        if (rem < 10) {
            temp[idx++] = rem + '0';
        } else {
            temp[idx++] = rem - 10 + 'A';
        }
        val /= base;
    }
    
    for (int i = 0; i < idx; i++) {
        buffer[i] = temp[idx - 1 - i];
    }
    buffer[idx] = '\0';
}

char* concatHex36(int n) {
    long long n2 = (long long)n * n;
    long long n3 = (long long)n * n * n;
    
    char hexStr[32];
    char base36Str[32];
    
    toBase(n2, 16, hexStr);
    toBase(n3, 36, base36Str);
    
    char* result = (char*)malloc((strlen(hexStr) + strlen(base36Str) + 1) * sizeof(char));
    strcpy(result, hexStr);
    strcat(result, base36Str);
    
    return result;
}