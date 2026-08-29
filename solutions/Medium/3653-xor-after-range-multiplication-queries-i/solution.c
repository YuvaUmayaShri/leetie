// ──────────────────────────────────────────────────
// Problem  : 3653. XOR After Range Multiplication Queries I
// Difficulty: Medium
// Tags     : Array, Divide and Conquer, Simulation, Prefix Sum
// Link     : https://leetcode.com/problems/xor-after-range-multiplication-queries-i/
// Runtime  : 67 ms (beats 47%)
// Memory   : 25604000 (beats 13%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    long long MOD = 1000000007;

    for (int i = 0; i < queriesSize; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        int k = queries[i][2];
        int v = queries[i][3];

        for (int idx = l; idx <= r; idx += k) {
            nums[idx] = (int)(((long long)nums[idx] * v) % MOD);
        }
    }

    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }

    return result;
}