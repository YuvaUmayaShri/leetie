// ──────────────────────────────────────────────────
// Problem  : 2165. Smallest Value of the Rearranged Number
// Difficulty: Medium
// Tags     : Math, Sorting
// Link     : https://leetcode.com/problems/smallest-value-of-the-rearranged-number/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8596000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

int cmpAsc(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

int cmpDesc(const void* a, const void* b) {
    return *(char*)b - *(char*)a;
}

long long smallestNumber(long long num) {
    if (num == 0) return 0;

    char str[20];
    sprintf(str, "%lld", num < 0 ? -num : num);
    int len = strlen(str);

    if (num > 0) {
        qsort(str, len, sizeof(char), cmpAsc);
        if (str[0] == '0') {
            for (int i = 1; i < len; i++) {
                if (str[i] != '0') {
                    str[0] = str[i];
                    str[i] = '0';
                    break;
                }
            }
        }
        return atoll(str);
    } else {
        qsort(str, len, sizeof(char), cmpDesc);
        return -atoll(str);
    }
}