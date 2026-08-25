// ──────────────────────────────────────────────────
// Problem  : 3074. Apple Redistribution into Boxes
// Difficulty: Easy
// Tags     : Array, Greedy, Sorting
// Link     : https://leetcode.com/problems/apple-redistribution-into-boxes/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9780000 (beats 46%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int total_apples = 0;
    for (int i = 0; i < appleSize; i++) {
        total_apples += apple[i];
    }

    qsort(capacity, capacitySize, sizeof(int), compare);

    int boxes = 0;
    for (int i = 0; i < capacitySize; i++) {
        total_apples -= capacity[i];
        boxes++;
        if (total_apples <= 0) {
            break;
        }
    }

    return boxes;
}