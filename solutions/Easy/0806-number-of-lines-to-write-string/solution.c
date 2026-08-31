// ──────────────────────────────────────────────────
// Problem  : 806. Number of Lines To Write String
// Difficulty: Easy
// Tags     : Array, String
// Link     : https://leetcode.com/problems/number-of-lines-to-write-string/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8468000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    int lines = 1;
    int current_width = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int char_width = widths[s[i] - 'a'];
        if (current_width + char_width > 100) {
            lines++;
            current_width = char_width;
        } else {
            current_width += char_width;
        }
    }

    result[0] = lines;
    result[1] = current_width;

    return result;
}