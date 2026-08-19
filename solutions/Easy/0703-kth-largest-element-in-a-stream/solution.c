// ──────────────────────────────────────────────────
// Problem  : 703. Kth Largest Element in a Stream
// Difficulty: Easy
// Tags     : Tree, Design, Binary Search Tree, Heap (Priority Queue), Binary Tree, Data Stream
// Link     : https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Runtime  : 8 ms (beats 65%)
// Memory   : 23188000 (beats 98%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* heap;
    int size;
    int capacity;
} KthLargest;

static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void minHeapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index]) break;
        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

static void minHeapifyDown(int* heap, int size, int index) {
    while (2 * index + 1 < size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest == index) break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->capacity) {
        obj->heap[obj->size] = val;
        minHeapifyUp(obj->heap, obj->size);
        obj->size++;
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        minHeapifyDown(obj->heap, obj->size, 0);
    }
    return obj->heap[0];
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->capacity = k;
    obj->size = 0;
    obj->heap = (int*)malloc(sizeof(int) * k);

    for (int i = 0; i < numsSize; i++) {
        kthLargestAdd(obj, nums[i]);
    }

    return obj;
}

void kthLargestFree(KthLargest* obj) {
    if (obj) {
        free(obj->heap);
        free(obj);
    }
}