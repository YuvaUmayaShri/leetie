// ──────────────────────────────────────────────────
// Problem  : 373. Find K Pairs with Smallest Sums
// Difficulty: Medium
// Tags     : Array, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// Runtime  : 30 ms (beats 32%)
// Memory   : 61056000 (beats 90%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sum;
    int i;
    int j;
} Pair;

void swap(Pair* a, Pair* b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(Pair* heap, int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && heap[left].sum < heap[smallest].sum) {
        smallest = left;
    }
    if (right < size && heap[right].sum < heap[smallest].sum) {
        smallest = right;
    }

    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void push(Pair* heap, int* size, Pair val) {
    heap[*size] = val;
    int curr = *size;
    (*size)++;

    while (curr > 0 && heap[curr].sum < heap[(curr - 1) / 2].sum) {
        swap(&heap[curr], &heap[(curr - 1) / 2]);
        curr = (curr - 1) / 2;
    }
}

Pair pop(Pair* heap, int* size) {
    Pair top = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, *size, 0);
    return top;
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes) {
    int maxPairs = (nums1Size < k) ? nums1Size : k;
    Pair* heap = (Pair*)malloc(maxPairs * sizeof(Pair));
    int heapSize = 0;

    for (int i = 0; i < maxPairs; i++) {
        Pair p = {nums1[i] + nums2[0], i, 0};
        push(heap, &heapSize, p);
    }

    int resultCapacity = (k < (long long)nums1Size * nums2Size) ? k : (nums1Size * nums2Size);
    int** result = (int**)malloc(resultCapacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(resultCapacity * sizeof(int));
    *returnSize = 0;

    while (heapSize > 0 && *returnSize < resultCapacity) {
        Pair top = pop(heap, &heapSize);
        int i = top.i;
        int j = top.j;

        result[*returnSize] = (int*)malloc(2 * sizeof(int));
        result[*returnSize][0] = nums1[i];
        result[*returnSize][1] = nums2[j];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;

        if (j + 1 < nums2Size) {
            Pair nextPair = {nums1[i] + nums2[j + 1], i, j + 1};
            push(heap, &heapSize, nextPair);
        }
    }

    free(heap);
    return result;
}