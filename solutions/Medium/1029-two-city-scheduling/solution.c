// ──────────────────────────────────────────────────
// Problem  : 1029. Two City Scheduling
// Difficulty: Medium
// Tags     : Array, Greedy, Sorting, Hungarian Algorithm, Successive Shortest Path Algorithm
// Link     : https://leetcode.com/problems/two-city-scheduling/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8612000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* costA = *(int**)a;
    int* costB = *(int**)b;
    return (costA[0] - costA[1]) - (costB[0] - costB[1]);
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize) {
    qsort(costs, costsSize, sizeof(int*), cmp);

    int totalCost = 0;
    int n = costsSize / 2;

    for (int i = 0; i < n; i++) {
        totalCost += costs[i][0];
    }
    for (int i = n; i < costsSize; i++) {
        totalCost += costs[i][1];
    }

    return totalCost;
}