// ──────────────────────────────────────────────────
// Problem  : 1094. Car Pooling
// Difficulty: Medium
// Tags     : Array, Sorting, Heap (Priority Queue), Simulation, Prefix Sum
// Link     : https://leetcode.com/problems/car-pooling/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8524000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    int passenger_change[1001] = {0};

    for (int i = 0; i < tripsSize; i++) {
        int numPassengers = trips[i][0];
        int from = trips[i][1];
        int to = trips[i][2];

        passenger_change[from] += numPassengers;
        passenger_change[to] -= numPassengers;
    }

    int current_passengers = 0;
    for (int i = 0; i <= 1000; i++) {
        current_passengers += passenger_change[i];
        if (current_passengers > capacity) {
            return false;
        }
    }

    return true;
}