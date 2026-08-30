// ──────────────────────────────────────────────────
// Problem  : 2274. Maximum Consecutive Floors Without Special Floors
// Difficulty: Medium
// Tags     : Array, Sorting
// Link     : https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/
// Runtime  : 59 ms (beats 100%)
// Memory   : 17752000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maxConsecutive(int bottom, int top, int* special, int specialSize) {
    qsort(special, specialSize, sizeof(int), cmp);

    int maxFloors = MAX(special[0] - bottom, top - special[specialSize - 1]);

    for (int i = 1; i < specialSize; i++) {
        int diff = special[i] - special[i - 1] - 1;
        if (diff > maxFloors) {
            maxFloors = diff;
        }
    }

    return maxFloors;
}