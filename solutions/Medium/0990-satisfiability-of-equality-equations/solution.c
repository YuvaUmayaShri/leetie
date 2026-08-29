// ──────────────────────────────────────────────────
// Problem  : 990. Satisfiability of Equality Equations
// Difficulty: Medium
// Tags     : Array, String, Union-Find, Graph Theory
// Link     : https://leetcode.com/problems/satisfiability-of-equality-equations/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9224000 (beats 60%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>

int find(int* parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSets(int* parent, int i, int j) {
    int rootI = find(parent, i);
    int rootJ = find(parent, j);
    if (rootI != rootJ) {
        parent[rootI] = rootJ;
    }
}

bool equationsPossible(char** equations, int equationsSize) {
    int parent[26];
    for (int i = 0; i < 26; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '=') {
            int u = equations[i][0] - 'a';
            int v = equations[i][3] - 'a';
            unionSets(parent, u, v);
        }
    }

    for (int i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '!') {
            int u = equations[i][0] - 'a';
            int v = equations[i][3] - 'a';
            if (find(parent, u) == find(parent, v)) {
                return false;
            }
        }
    }

    return true;
}