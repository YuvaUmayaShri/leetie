// ──────────────────────────────────────────────────
// Problem  : 2178. Maximum Split of Positive Even Integers
// Difficulty: Medium
// Tags     : Math, Backtracking, Greedy
// Link     : https://leetcode.com/problems/maximum-split-of-positive-even-integers/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8440000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

long long* maximumEvenSplit(long long finalSum, int* returnSize) {
    if (finalSum % 2 != 0) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 100000;
    long long* result = (long long*)malloc(capacity * sizeof(long long));
    int count = 0;
    long long current = 2;

    while (finalSum >= current) {
        result[count++] = current;
        finalSum -= current;
        current += 2;
    }

    if (finalSum > 0) {
        result[count - 1] += finalSum;
    }

    *returnSize = count;
    return result;
}