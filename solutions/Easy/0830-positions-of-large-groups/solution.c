// ──────────────────────────────────────────────────
// Problem  : 830. Positions of Large Groups
// Difficulty: Easy
// Tags     : String
// Link     : https://leetcode.com/problems/positions-of-large-groups/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8556000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);
    int capacity = 10;
    int count = 0;
    
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    
    int start = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] != s[start]) {
            int length = i - start;
            if (length >= 3) {
                if (count >= capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }
                
                result[count] = (int*)malloc(2 * sizeof(int));
                result[count][0] = start;
                result[count][1] = i - 1;
                (*returnColumnSizes)[count] = 2;
                count++;
            }
            start = i;
        }
    }
    
    *returnSize = count;
    return result;
}