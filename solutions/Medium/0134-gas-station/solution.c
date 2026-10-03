// ──────────────────────────────────────────────────
// Problem  : 134. Gas Station
// Difficulty: Medium
// Tags     : Array, Greedy
// Link     : https://leetcode.com/problems/gas-station/
// Runtime  : 0 ms (beats 100%)
// Memory   : 16492000 (beats 35%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int total_gas = 0;
    int total_cost = 0;
    int current_tank = 0;
    int start_index = 0;

    for (int i = 0; i < gasSize; i++) {
        total_gas += gas[i];
        total_cost += cost[i];
        current_tank += gas[i] - cost[i];

        if (current_tank < 0) {
            start_index = i + 1;
            current_tank = 0;
        }
    }

    return (total_gas >= total_cost) ? start_index : -1;
}