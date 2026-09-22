// ──────────────────────────────────────────────────
// Problem  : 587. Erect the Fence
// Difficulty: Hard
// Tags     : Array, Math, Geometry, Convex Hull, Polygons
// Link     : https://leetcode.com/problems/erect-the-fence/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8696000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

static int comparePoints(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    if (p1[0] != p2[0]) {
        return p1[0] - p2[0];
    }
    return p1[1] - p2[1];
}

static int crossProduct(int* p1, int* p2, int* p3) {
    return (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0]);
}

int** outerTrees(int** trees, int treesSize, int* treesColSize, int* returnSize, int** returnColumnSizes) {
    if (treesSize <= 3) {
        *returnSize = treesSize;
        *returnColumnSizes = (int*)malloc(treesSize * sizeof(int));
        int** res = (int**)malloc(treesSize * sizeof(int*));
        for (int i = 0; i < treesSize; i++) {
            (*returnColumnSizes)[i] = 2;
            res[i] = (int*)malloc(2 * sizeof(int));
            res[i][0] = trees[i][0];
            res[i][1] = trees[i][1];
        }
        return res;
    }

    qsort(trees, treesSize, sizeof(int*), comparePoints);

    int* hull = (int*)malloc(2 * treesSize * sizeof(int));
    int k = 0;

    for (int i = 0; i < treesSize; i++) {
        while (k >= 2 && crossProduct(trees[hull[k - 2]], trees[hull[k - 1]], trees[i]) < 0) {
            k--;
        }
        hull[k++] = i;
    }

    for (int i = treesSize - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && crossProduct(trees[hull[k - 2]], trees[hull[k - 1]], trees[i]) < 0) {
            k--;
        }
        hull[k++] = i;
    }

    int* used = (int*)calloc(treesSize, sizeof(int));
    int unique_count = 0;
    for (int i = 0; i < k; i++) {
        if (!used[hull[i]]) {
            used[hull[i]] = 1;
            unique_count++;
        }
    }

    int** result = (int**)malloc(unique_count * sizeof(int*));
    *returnColumnSizes = (int*)malloc(unique_count * sizeof(int));
    *returnSize = unique_count;

    int idx = 0;
    for (int i = 0; i < treesSize; i++) {
        if (used[i]) {
            (*returnColumnSizes)[idx] = 2;
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = trees[i][0];
            result[idx][1] = trees[i][1];
            idx++;
        }
    }

    free(hull);
    free(used);

    return result;
}