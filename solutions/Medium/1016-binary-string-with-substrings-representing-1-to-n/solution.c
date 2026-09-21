// ──────────────────────────────────────────────────
// Problem  : 1016. Binary String With Substrings Representing 1 To N
// Difficulty: Medium
// Tags     : Hash Table, String, Bit Manipulation, Sliding Window
// Link     : https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8700000 (beats 75%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <string.h>

bool queryString(char* s, int n) {
    for (int i = n; i > n / 2; i--) {
        char binary[33];
        int idx = 0;
        int temp = i;

        while (temp > 0) {
            binary[idx++] = (temp & 1) ? '1' : '0';
            temp >>= 1;
        }

        // Reverse the string to get the correct binary representation
        for (int j = 0; j < idx / 2; j++) {
            char t = binary[j];
            binary[j] = binary[idx - 1 - j];
            binary[idx - 1 - j] = t;
        }
        binary[idx] = '\0';

        if (strstr(s, binary) == NULL) {
            return false;
        }
    }

    return true;
}