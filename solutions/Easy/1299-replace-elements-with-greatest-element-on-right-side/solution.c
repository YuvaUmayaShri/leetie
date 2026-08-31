// ──────────────────────────────────────────────────
// Problem  : 1299. Replace Elements with Greatest Element on Right Side
// Difficulty: Easy
// Tags     : Array
// Link     : https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8608000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    int* result = (int*)malloc(arrSize * sizeof(int));
    
    int max_so_far = -1;

    for (int i = arrSize - 1; i >= 0; i--) {
        result[i] = max_so_far;
        if (arr[i] > max_so_far) {
            max_so_far = arr[i];
        }
    }

    return result;
}