// ──────────────────────────────────────────────────
// Problem  : 2231. Largest Number After Digit Swaps by Parity
// Difficulty: Easy
// Tags     : Sorting, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8772000 (beats 58%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

int cmpAsc(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

int largestInteger(int num) {
    char str[12];
    sprintf(str, "%d", num);
    int len = strlen(str);

    char evens[12], odds[12];
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < len; i++) {
        if ((str[i] - '0') % 2 == 0) {
            evens[evenCount++] = str[i];
        } else {
            odds[oddCount++] = str[i];
        }
    }

    qsort(evens, evenCount, sizeof(char), cmpAsc);
    qsort(odds, oddCount, sizeof(char), cmpAsc);

    for (int i = 0; i < len; i++) {
        if ((str[i] - '0') % 2 == 0) {
            str[i] = evens[--evenCount];
        } else {
            str[i] = odds[--oddCount];
        }
    }

    return atoi(str);
}