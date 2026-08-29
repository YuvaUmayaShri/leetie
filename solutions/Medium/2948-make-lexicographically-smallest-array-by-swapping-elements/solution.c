// ──────────────────────────────────────────────────
// Problem  : 2948. Make Lexicographically Smallest Array by Swapping Elements
// Difficulty: Medium
// Tags     : Array, Union-Find, Sorting
// Link     : https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/
// Runtime  : 80 ms (beats 100%)
// Memory   : 110864000 (beats 40%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Element;

int compareElements(const void* a, const void* b) {
    return ((Element*)a)->val - ((Element*)b)->val;
}

int compareInts(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* lexicographicallySmallestArray(int* nums, int numsSize, int limit, int* returnSize) {
    *returnSize = numsSize;
    
    Element* sorted = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; i++) {
        sorted[i].val = nums[i];
        sorted[i].idx = i;
    }

    qsort(sorted, numsSize, sizeof(Element), compareElements);

    int* res = (int*)malloc(numsSize * sizeof(int));
    int* groupIndices = (int*)malloc(numsSize * sizeof(int));

    int i = 0;
    while (i < numsSize) {
        int j = i;
        while (j + 1 < numsSize && sorted[j + 1].val - sorted[j].val <= limit) {
            j++;
        }

        int groupSize = j - i + 1;
        for (int k = 0; k < groupSize; k++) {
            groupIndices[k] = sorted[i + k].idx;
        }

        qsort(groupIndices, groupSize, sizeof(int), compareInts);

        for (int k = 0; k < groupSize; k++) {
            res[groupIndices[k]] = sorted[i + k].val;
        }

        i = j + 1;
    }

    free(sorted);
    free(groupIndices);

    return res;
}