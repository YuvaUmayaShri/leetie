// ──────────────────────────────────────────────────
// Problem  : 347. Top K Frequent Elements
// Difficulty: Medium
// Tags     : Array, Hash Table, Divide and Conquer, Sorting, Heap (Priority Queue), Bucket Sort, Counting, Quickselect
// Link     : https://leetcode.com/problems/top-k-frequent-elements/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12312000 (beats 61%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

typedef struct {
    int val;
    int freq;
} Pair;

static int comparePairs(const void* a, const void* b) {
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;
    return p2->freq - p1->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int max_val = nums[0];
    int min_val = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max_val) max_val = nums[i];
        if (nums[i] < min_val) min_val = nums[i];
    }

    int range = max_val - min_val + 1;
    int* counts = (int*)calloc(range, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        counts[nums[i] - min_val]++;
    }

    int unique_count = 0;
    for (int i = 0; i < range; i++) {
        if (counts[i] > 0) unique_count++;
    }

    Pair* pairs = (Pair*)malloc(unique_count * sizeof(Pair));
    int idx = 0;
    for (int i = 0; i < range; i++) {
        if (counts[i] > 0) {
            pairs[idx].val = i + min_val;
            pairs[idx].freq = counts[i];
            idx++;
        }
    }

    free(counts);

    qsort(pairs, unique_count, sizeof(Pair), comparePairs);

    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = pairs[i].val;
    }

    free(pairs);

    *returnSize = k;
    return result;
}