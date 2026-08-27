// ──────────────────────────────────────────────────
// Problem  : 997. Find the Town Judge
// Difficulty: Easy
// Tags     : Array, Hash Table, Graph Theory
// Link     : https://leetcode.com/problems/find-the-town-judge/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8628000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int count[n + 1];
    for (int i = 0; i <= n; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < trustSize; i++) {
        count[trust[i][0]]--;
        count[trust[i][1]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (count[i] == n - 1) {
            return i;
        }
    }

    return -1;
}