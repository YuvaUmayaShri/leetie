// ──────────────────────────────────────────────────
// Problem  : 1691. Maximum Height by Stacking Cuboids 
// Difficulty: Hard
// Tags     : Array, Dynamic Programming, Sorting
// Link     : https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
// Runtime  : 10 ms (beats 0%)
// Memory   : 10260000 (beats 75%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compareCuboids(const void* a, const void* b) {
    int* c1 = *(int**)a;
    int* c2 = *(int**)b;
    if (c1[0] != c2[0]) return c1[0] - c2[0];
    if (c1[1] != c2[1]) return c1[1] - c2[1];
    return c1[2] - c2[2];
}

int maxHeight(int** cuboids, int cuboidsSize, int* cuboidsColSize) {
    // Sort dimensions of each cuboid so width <= length <= height
    for (int i = 0; i < cuboidsSize; i++) {
        qsort(cuboids[i], 3, sizeof(int), compareInts);
    }

    // Sort all cuboids lexicographically
    qsort(cuboids, cuboidsSize, sizeof(int*), compareCuboids);

    int* dp = (int*)malloc(cuboidsSize * sizeof(int));
    int max_total_height = 0;

    for (int i = 0; i < cuboidsSize; i++) {
        dp[i] = cuboids[i][2];
        for (int j = 0; j < i; j++) {
            if (cuboids[j][0] <= cuboids[i][0] &&
                cuboids[j][1] <= cuboids[i][1] &&
                cuboids[j][2] <= cuboids[i][2]) {
                if (dp[j] + cuboids[i][2] > dp[i]) {
                    dp[i] = dp[j] + cuboids[i][2];
                }
            }
        }
        if (dp[i] > max_total_height) {
            max_total_height = dp[i];
        }
    }

    free(dp);
    return max_total_height;
}