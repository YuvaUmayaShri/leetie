// ──────────────────────────────────────────────────
// Problem  : 839. Similar String Groups
// Difficulty: Hard
// Tags     : Array, Hash Table, String, Depth-First Search, Breadth-First Search, Union-Find
// Link     : https://leetcode.com/problems/similar-string-groups/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8480000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool isSimilar(char* s1, char* s2) {
    int diff = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            diff++;
            if (diff > 2) return false;
        }
    }
    return diff == 0 || diff == 2;
}

int find(int* parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSet(int* parent, int i, int j, int* groups) {
    int rootI = find(parent, i);
    int rootJ = find(parent, j);
    if (rootI != rootJ) {
        parent[rootI] = rootJ;
        (*groups)--;
    }
}

int numSimilarGroups(char** strs, int strsSize) {
    int parent[strsSize];
    for (int i = 0; i < strsSize; i++) {
        parent[i] = i;
    }

    int groups = strsSize;

    for (int i = 0; i < strsSize; i++) {
        for (int j = i + 1; j < strsSize; j++) {
            if (isSimilar(strs[i], strs[j])) {
                unionSet(parent, i, j, &groups);
            }
        }
    }

    return groups;
}