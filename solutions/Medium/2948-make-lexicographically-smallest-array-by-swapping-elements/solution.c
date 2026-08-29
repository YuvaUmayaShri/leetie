// ──────────────────────────────────────────────────
// Problem  : 2948. Make Lexicographically Smallest Array by Swapping Elements
// Difficulty: Medium
// Tags     : Array, Union-Find, Sorting
// Link     : https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/
// Runtime  : 112 ms (beats 80%)
// Memory   : 119812000 (beats 40%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Pair;

int comparePairs(const void *a, const void *b) {
    return ((Pair *)a)->val - ((Pair *)b)->val;
}

int compareInts(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* lexicographicallySmallestArray(int* nums, int numsSize, int limit, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    Pair* sorted_nums = (Pair*)malloc(numsSize * sizeof(Pair));

    for (int i = 0; i < numsSize; i++) {
        sorted_nums[i].val = nums[i];
        sorted_nums[i].index = i;
    }

    qsort(sorted_nums, numsSize, sizeof(Pair), comparePairs);

    int i = 0;
    while (i < numsSize) {
        int j = i;
        while (j + 1 < numsSize && sorted_nums[j + 1].val - sorted_nums[j].val <= limit) {
            j++;
        }

        int groupSize = j - i + 1;
        int* indices = (int*)malloc(groupSize * sizeof(int));

        for (int k = 0; k < groupSize; k++) {
            indices[k] = sorted_nums[i + k].index;
        }

        qsort(indices, groupSize, sizeof(int), compareInts);

        for (int k = 0; k < groupSize; k++) {
            result[indices[k]] = sorted_nums[i + k].val;
        }

        free(indices);
        i = j + 1;
    }

    free(sorted_nums);
    return result;
}