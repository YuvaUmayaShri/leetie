// ──────────────────────────────────────────────────
// Problem  : 1632. Rank Transform of a Matrix
// Difficulty: Hard
// Tags     : Array, Union-Find, Graph Theory, Topological Sort, Sorting, Matrix
// Link     : https://leetcode.com/problems/rank-transform-of-a-matrix/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8624000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int r;
    int c;
} Element;

typedef struct {
    int parent;
    int maxRank;
} DSU;

int cmpElements(const void* a, const void* b) {
    return ((Element*)a)->val - ((Element*)b)->val;
}

int find(DSU* dsu, int i) {
    if (dsu[i].parent == i)
        return i;
    return dsu[i].parent = find(dsu, dsu[i].parent);
}

void unionSet(DSU* dsu, int i, int j) {
    int rootI = find(dsu, i);
    int rootJ = find(dsu, j);
    if (rootI != rootJ) {
        dsu[rootI].parent = rootJ;
        if (dsu[rootI].maxRank > dsu[rootJ].maxRank) {
            dsu[rootJ].maxRank = dsu[rootI].maxRank;
        }
    }
}

int** matrixRankTransform(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int m = matrixSize;
    int n = matrixColSize[0];

    Element* elements = (Element*)malloc(m * n * sizeof(Element));
    int totalElements = 0;

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            elements[totalElements].val = matrix[r][c];
            elements[totalElements].r = r;
            elements[totalElements].c = c;
            totalElements++;
        }
    }

    qsort(elements, totalElements, sizeof(Element), cmpElements);

    int* rank = (int*)calloc(m + n, sizeof(int));
    DSU* dsu = (DSU*)malloc((m + n) * sizeof(DSU));

    int** answer = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int r = 0; r < m; r++) {
        answer[r] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[r] = n;
    }
    *returnSize = m;

    int i = 0;
    while (i < totalElements) {
        int start = i;
        while (i < totalElements && elements[i].val == elements[start].val) {
            i++;
        }

        for (int k = start; k < i; k++) {
            int r = elements[k].r;
            int c = elements[k].c;

            dsu[r].parent = r;
            dsu[r].maxRank = rank[r];

            dsu[m + c].parent = m + c;
            dsu[m + c].maxRank = rank[m + c];
        }

        for (int k = start; k < i; k++) {
            int r = elements[k].r;
            int c = elements[k].c;
            unionSet(dsu, r, m + c);
        }

        for (int k = start; k < i; k++) {
            int r = elements[k].r;
            int c = elements[k].c;
            int root = find(dsu, r);
            int newRank = dsu[root].maxRank + 1;

            answer[r][c] = newRank;
            rank[r] = newRank > rank[r] ? newRank : rank[r];
            rank[m + c] = newRank > rank[m + c] ? newRank : rank[m + c];
        }
    }

    free(elements);
    free(rank);
    free(dsu);

    return answer;
}