// ──────────────────────────────────────────────────
// Problem  : 480. Sliding Window Median
// Difficulty: Hard
// Tags     : Array, Hash Table, Sliding Window, Heap (Priority Queue), Treap
// Link     : https://leetcode.com/problems/sliding-window-median/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8488000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct {
    int* tree;
    int size;
} Fenwick;

void initFenwick(Fenwick* f, int size) {
    f->size = size;
    f->tree = (int*)calloc(size + 1, sizeof(int));
}

void updateFenwick(Fenwick* f, int idx, int val) {
    for (; idx <= f->size; idx += idx & -idx) {
        f->tree[idx] += val;
    }
}

int queryFenwick(Fenwick* f, int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += f->tree[idx];
    }
    return sum;
}

typedef struct {
    int val;
    int original_idx;
} Element;

int compareElements(const void* a, const void* b) {
    int v1 = ((Element*)a)->val;
    int v2 = ((Element*)b)->val;
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}

int findKth(Fenwick* f, int k) {
    int idx = 0;
    for (int i = 1 << 17; i > 0; i >>= 1) {
        if (idx + i <= f->size && f->tree[idx + i] < k) {
            idx += i;
            k -= f->tree[idx];
        }
    }
    return idx + 1;
}

double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int count = numsSize - k + 1;
    double* result = (double*)malloc(count * sizeof(double));

    Element* sorted = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; i++) {
        sorted[i].val = nums[i];
        sorted[i].original_idx = i;
    }
    qsort(sorted, numsSize, sizeof(Element), compareElements);

    int* rank = (int*)malloc(numsSize * sizeof(int));
    int* sortedVals = (int*)malloc(numsSize * sizeof(int));
    int uniqueCount = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i == 0 || sorted[i].val != sorted[i - 1].val) {
            uniqueCount++;
            sortedVals[uniqueCount] = sorted[i].val;
        }
        rank[sorted[i].original_idx] = uniqueCount;
    }

    Fenwick fenwick;
    initFenwick(&fenwick, uniqueCount);

    for (int i = 0; i < k; i++) {
        updateFenwick(&fenwick, rank[i], 1);
    }

    for (int i = 0; i < count; i++) {
        if (k % 2 == 1) {
            int r = findKth(&fenwick, k / 2 + 1);
            result[i] = (double)sortedVals[r];
        } else {
            int r1 = findKth(&fenwick, k / 2);
            int r2 = findKth(&fenwick, k / 2 + 1);
            result[i] = ((double)sortedVals[r1] + (double)sortedVals[r2]) / 2.0;
        }

        if (i < count - 1) {
            updateFenwick(&fenwick, rank[i], -1);
            updateFenwick(&fenwick, rank[i + k], 1);
        }
    }

    free(sorted);
    free(rank);
    free(sortedVals);
    free(fenwick.tree);

    *returnSize = count;
    return result;
}