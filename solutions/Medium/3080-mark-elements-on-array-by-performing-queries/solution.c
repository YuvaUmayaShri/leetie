// ──────────────────────────────────────────────────
// Problem  : 3080. Mark Elements on Array by Performing Queries
// Difficulty: Medium
// Tags     : Array, Hash Table, Sorting, Heap (Priority Queue), Simulation
// Link     : https://leetcode.com/problems/mark-elements-on-array-by-performing-queries/
// Runtime  : 525 ms (beats 67%)
// Memory   : 68780000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int val;
    int idx;
} Element;

int compareElements(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    if (e1->val != e2->val) {
        return (e1->val < e2->val) ? -1 : 1;
    }
    return (e1->idx < e2->idx) ? -1 : 1;
}

long long* unmarkedSumArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    long long total_sum = 0;
    Element* sorted = (Element*)malloc(sizeof(Element) * numsSize);
    bool* marked = (bool*)calloc(numsSize, sizeof(bool));

    for (int i = 0; i < numsSize; i++) {
        total_sum += nums[i];
        sorted[i].val = nums[i];
        sorted[i].idx = i;
    }

    qsort(sorted, numsSize, sizeof(Element), compareElements);

    long long* ans = (long long*)malloc(sizeof(long long) * queriesSize);
    *returnSize = queriesSize;

    int ptr = 0;
    for (int i = 0; i < queriesSize; i++) {
        int idx = queries[i][0];
        int k = queries[i][1];

        if (!marked[idx]) {
            marked[idx] = true;
            total_sum -= nums[idx];
        }

        while (k > 0 && ptr < numsSize) {
            int orig_idx = sorted[ptr].idx;
            if (!marked[orig_idx]) {
                marked[orig_idx] = true;
                total_sum -= sorted[ptr].val;
                k--;
            }
            ptr++;
        }

        ans[i] = total_sum;
    }

    free(sorted);
    free(marked);
    return ans;
}