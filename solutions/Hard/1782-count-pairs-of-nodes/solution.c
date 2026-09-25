// ──────────────────────────────────────────────────
// Problem  : 1782. Count Pairs Of Nodes
// Difficulty: Hard
// Tags     : Array, Hash Table, Two Pointers, Binary Search, Graph Theory, Sorting, Counting
// Link     : https://leetcode.com/problems/count-pairs-of-nodes/
// Runtime  : 107 ms (beats 75%)
// Memory   : 55532000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

typedef struct {
    int u;
    int v;
    int count;
} UniqueEdge;

int compareEdges(const void* a, const void* b) {
    int* edgeA = *(int**)a;
    int* edgeB = *(int**)b;
    int uA = edgeA[0] < edgeA[1] ? edgeA[0] : edgeA[1];
    int vA = edgeA[0] < edgeA[1] ? edgeA[1] : edgeA[0];
    int uB = edgeB[0] < edgeB[1] ? edgeB[0] : edgeB[1];
    int vB = edgeB[0] < edgeB[1] ? edgeB[1] : edgeB[0];
    if (uA != uB) return uA - uB;
    return vA - vB;
}

int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* countPairs(int n, int** edges, int edgesSize, int* edgesColSize, int* queries, int queriesSize, int* returnSize) {
    int* deg = (int*)calloc(n + 1, sizeof(int));
    int* sortedDeg = (int*)malloc((n + 1) * sizeof(int));

    qsort(edges, edgesSize, sizeof(int*), compareEdges);

    UniqueEdge* uniqueEdges = (UniqueEdge*)malloc(edgesSize * sizeof(UniqueEdge));
    int uniqueCount = 0;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        deg[u]++;
        deg[v]++;

        int su = u < v ? u : v;
        int sv = u < v ? v : u;

        if (uniqueCount > 0 && uniqueEdges[uniqueCount - 1].u == su && uniqueEdges[uniqueCount - 1].v == sv) {
            uniqueEdges[uniqueCount - 1].count++;
        } else {
            uniqueEdges[uniqueCount].u = su;
            uniqueEdges[uniqueCount].v = sv;
            uniqueEdges[uniqueCount].count = 1;
            uniqueCount++;
        }
    }

    for (int i = 1; i <= n; i++) {
        sortedDeg[i] = deg[i];
    }
    qsort(sortedDeg + 1, n, sizeof(int), compareInts);

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

        for (int i = 0; i < uniqueCount; i++) {
            int u = uniqueEdges[i].u;
            int v = uniqueEdges[i].v;
            int count = uniqueEdges[i].count;

            if (deg[u] + deg[v] > limit && deg[u] + deg[v] - count <= limit) {
                totalPairs--;
            }
        }

        ans[q] = (int)totalPairs;
    }

    free(deg);
    free(sortedDeg);
    free(uniqueEdges);

    *returnSize = queriesSize;
    return ans;
}