// ──────────────────────────────────────────────────
// Problem  : 2037. Minimum Number of Moves to Seat Everyone
// Difficulty: Easy
// Tags     : Array, Greedy, Sorting, Counting Sort
// Link     : https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/
// Runtime  : 3 ms (beats 29%)
// Memory   : 9456000 (beats 22%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    qsort(seats, seatsSize, sizeof(int), cmp);
    qsort(students, studentsSize, sizeof(int), cmp);

    int totalMoves = 0;
    for (int i = 0; i < seatsSize; i++) {
        totalMoves += abs(seats[i] - students[i]);
    }

    return totalMoves;
}