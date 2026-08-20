// ──────────────────────────────────────────────────
// Problem  : 682. Baseball Game
// Difficulty: Easy
// Tags     : Array, Stack, Simulation
// Link     : https://leetcode.com/problems/baseball-game/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8972000 (beats 97%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int calPoints(char** operations, int operationsSize) {
    int* record = (int*)malloc(operationsSize * sizeof(int));
    int size = 0;

    for (int i = 0; i < operationsSize; i++) {
        if (operations[i][0] == '+') {
            record[size] = record[size - 1] + record[size - 2];
            size++;
        } else if (operations[i][0] == 'D') {
            record[size] = 2 * record[size - 1];
            size++;
        } else if (operations[i][0] == 'C') {
            size--;
        } else {
            record[size] = atoi(operations[i]);
            size++;
        }
    }

    int totalSum = 0;
    for (int i = 0; i < size; i++) {
        totalSum += record[i];
    }

    free(record);
    return totalSum;
}