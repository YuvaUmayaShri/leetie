// ──────────────────────────────────────────────────
// Problem  : 1710. Maximum Units on a Truck
// Difficulty: Easy
// Tags     : Array, Greedy, Sorting
// Link     : https://leetcode.com/problems/maximum-units-on-a-truck/
// Runtime  : 0 ms (beats 100%)
// Memory   : 11724000 (beats 85%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* boxA = *(int**)a;
    int* boxB = *(int**)b;
    return boxB[1] - boxA[1];
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
    qsort(boxTypes, boxTypesSize, sizeof(int*), compare);

    int totalUnits = 0;

    for (int i = 0; i < boxTypesSize && truckSize > 0; i++) {
        int count = boxTypes[i][0] < truckSize ? boxTypes[i][0] : truckSize;
        totalUnits += count * boxTypes[i][1];
        truckSize -= count;
    }

    return totalUnits;
}