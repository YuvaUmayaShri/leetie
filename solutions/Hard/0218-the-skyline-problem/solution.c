// ──────────────────────────────────────────────────
// Problem  : 218. The Skyline Problem
// Difficulty: Hard
// Tags     : Array, Divide and Conquer, Binary Indexed Tree, Segment Tree, Sweep Line, Sorting, Heap (Priority Queue), Ordered Set
// Link     : https://leetcode.com/problems/the-skyline-problem/
// Runtime  : 12 ms (beats 72%)
// Memory   : 24876000 (beats 71%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int height;
} Event;

typedef struct {
    int* tree;
    int size;
} MaxHeap;

int compareEvents(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    if (e1->x != e2->x) {
        return e1->x - e2->x;
    }
    return e1->height - e2->height;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pushHeap(MaxHeap* heap, int val) {
    heap->tree[++heap->size] = val;
    int i = heap->size;
    while (i > 1 && heap->tree[i] > heap->tree[i / 2]) {
        swap(&heap->tree[i], &heap->tree[i / 2]);
        i /= 2;
    }
}

void popHeap(MaxHeap* heap) {
    if (heap->size == 0) return;
    heap->tree[1] = heap->tree[heap->size--];
    int i = 1;
    while (2 * i <= heap->size) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int maxChild = left;
        if (right <= heap->size && heap->tree[right] > heap->tree[left]) {
            maxChild = right;
        }
        if (heap->tree[i] < heap->tree[maxChild]) {
            swap(&heap->tree[i], &heap->tree[maxChild]);
            i = maxChild;
        } else {
            break;
        }
    }
}

int getMax(MaxHeap* maxHeap, MaxHeap* delayedHeap) {
    while (delayedHeap->size > 0 && maxHeap->tree[1] == delayedHeap->tree[1]) {
        popHeap(maxHeap);
        popHeap(delayedHeap);
    }
    return maxHeap->tree[1];
}

int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes) {
    Event* events = (Event*)malloc(sizeof(Event) * buildingsSize * 2);
    int eventCount = 0;

    for (int i = 0; i < buildingsSize; i++) {
        events[eventCount].x = buildings[i][0];
        events[eventCount].height = -buildings[i][2];
        eventCount++;

        events[eventCount].x = buildings[i][1];
        events[eventCount].height = buildings[i][2];
        eventCount++;
    }

    qsort(events, eventCount, sizeof(Event), compareEvents);

    MaxHeap maxHeap;
    maxHeap.tree = (int*)malloc(sizeof(int) * (eventCount + 2));
    maxHeap.size = 0;

    MaxHeap delayedHeap;
    delayedHeap.tree = (int*)malloc(sizeof(int) * (eventCount + 2));
    delayedHeap.size = 0;

    pushHeap(&maxHeap, 0);

    int** result = (int**)malloc(sizeof(int*) * eventCount);
    *returnColumnSizes = (int*)malloc(sizeof(int) * eventCount);
    *returnSize = 0;

    int prevMaxHeight = 0;

    for (int i = 0; i < eventCount; i++) {
        int x = events[i].x;
        int h = events[i].height;

        if (h < 0) {
            pushHeap(&maxHeap, -h);
        } else {
            pushHeap(&delayedHeap, h);
        }

        int currentMaxHeight = getMax(&maxHeap, &delayedHeap);

        if (currentMaxHeight != prevMaxHeight) {
            result[*returnSize] = (int*)malloc(sizeof(int) * 2);
            result[*returnSize][0] = x;
            result[*returnSize][1] = currentMaxHeight;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
            prevMaxHeight = currentMaxHeight;
        }
    }

    free(events);
    free(maxHeap.tree);
    free(delayedHeap.tree);

    return result;
}