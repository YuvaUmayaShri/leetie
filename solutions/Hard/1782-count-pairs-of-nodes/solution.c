// ──────────────────────────────────────────────────
// Problem  : 1782. Count Pairs Of Nodes
// Difficulty: Hard
// Tags     : Array, Hash Table, Two Pointers, Binary Search, Graph Theory, Sorting, Counting
// Link     : https://leetcode.com/problems/count-pairs-of-nodes/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8596000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* countPairs(int n, int** edges, int edgesSize, int* edgesColSize, int* queries, int queriesSize, int* returnSize) {
    int* deg = (int*)calloc(n + 1, sizeof(int));
    int* sortedDeg = (int*)malloc((n + 1) * sizeof(int));

    int edgeCount = edgesSize;
    long long* edgeKeys = (long long*)malloc(edgeCount * sizeof(long long));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        deg[u]++;
        deg[v]++;

        if (u > v) {
            int temp = u;
            u = v;
            v = temp;
        }
        edgeKeys[i] = ((long long)u << 32) | (unsigned int)v;
    }

    for (int i = 1; i <= n; i++) {
        sortedDeg[i] = deg[i];
    }
    qsort(sortedDeg + 1, n, sizeof(int), compareInts);

    qsort(edgeKeys, edgeCount, sizeof(long long), compareInts);

    int* ans = (int*)malloc(queriesSize * sizeof(int));

    for (int q = 0; q < queriesSize; q++) {
        int limit = queries[q];
        long long totalPairs = 0;

        int left = 1, right = n;
        while (left < right) {
            if (sortedDeg[left] + sortedDeg[right] > limit) {
                totalPairs += (right - left);
                right--;
            } else {
                left++;
            }
        }

        int i = 0;
        while (i < edgeCount) {
            int j = i;
            while (j < edgeCount && edgeKeys[j] == edgeKeys[i]) {
                j++;
            }

            int count = j - i;
            int u = (int)(edgeKeys[i] >> 32);
            int v = (int)(edgeKeys[i] & 0xFFFFFFFF);

            if (deg[u] + deg[v] > limit && deg[u] + deg[v] - count <= limit) {
                totalPairs--;
            }

            i = j;
        }

        ans[q] = (int)totalPairs;
    }

    free(deg);
    free(sortedDeg);
    free(edgeKeys);

    *returnSize = queriesSize;
    return ans;
}