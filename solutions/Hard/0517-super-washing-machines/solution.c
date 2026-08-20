// ──────────────────────────────────────────────────
// Problem  : 517. Super Washing Machines
// Difficulty: Hard
// Tags     : Array, Greedy
// Link     : https://leetcode.com/problems/super-washing-machines/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9184000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <math.h>
#include <stdlib.h>

int findMinMoves(int* machines, int machinesSize) {
    int total = 0;
    for (int i = 0; i < machinesSize; i++) {
        total += machines[i];
    }

    if (total % machinesSize != 0) {
        return -1;
    }

    int avg = total / machinesSize;
    int maxMoves = 0;
    int currSum = 0;

    for (int i = 0; i < machinesSize; i++) {
        int diff = machines[i] - avg;
        currSum += diff;

        int maxVal = abs(currSum) > diff ? abs(currSum) : diff;
        if (maxVal > maxMoves) {
            maxMoves = maxVal;
        }
    }

    return maxMoves;
}