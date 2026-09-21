// ──────────────────────────────────────────────────
// Problem  : 978. Longest Turbulent Subarray
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Sliding Window
// Link     : https://leetcode.com/problems/longest-turbulent-subarray/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8372000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int compare(int a, int b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

int maxTurbulenceSize(int* arr, int arrSize) {
    if (arrSize <= 1) {
        return arrSize;
    }

    int maxLen = 1;
    int anchor = 0;

    for (int i = 1; i < arrSize; i++) {
        int c = compare(arr[i - 1], arr[i]);
        if (c == 0) {
            anchor = i;
        } else if (i == arrSize - 1 || c * compare(arr[i], arr[i + 1]) != -1) {
            maxLen = MAX(maxLen, i - anchor + 1);
            anchor = i;
        }
    }

    return maxLen;
}