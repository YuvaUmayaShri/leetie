// ──────────────────────────────────────────────────
// Problem  : 1606. Find Servers That Handled Most Number of Requests
// Difficulty: Hard
// Tags     : Array, Heap (Priority Queue), Simulation, Ordered Set
// Link     : https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8692000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    long long free_time;
    int server_id;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (HeapNode*)malloc((capacity + 1) * sizeof(HeapNode));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* heap, long long free_time, int server_id) {
    heap->size++;
    int i = heap->size;
    heap->data[i].free_time = free_time;
    heap->data[i].server_id = server_id;

    while (i > 1 && heap->data[i].free_time < heap->data[i / 2].free_time) {
        swap(&heap->data[i], &heap->data[i / 2]);
        i /= 2;
    }
}

HeapNode pop(MinHeap* heap) {
    HeapNode top = heap->data[1];
    heap->data[1] = heap->data[heap->size];
    heap->size--;

    int i = 1;
    while (i * 2 <= heap->size) {
        int left = i * 2;
        int right = i * 2 + 1;
        int smallest = i;

        if (left <= heap->size && heap->data[left].free_time < heap->data[smallest].free_time) {
            smallest = left;
        }
        if (right <= heap->size && heap->data[right].free_time < heap->data[smallest].free_time) {
            smallest = right;
        }

        if (smallest == i) break;
        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }

    return top;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* busiestServers(int k, int* arrival, int arrivalSize, int* load, int loadSize, int* returnSize) {
    MinHeap* busy = createHeap(k);
    bool* is_free = (bool*)malloc(k * sizeof(bool));
    int* count = (int*)calloc(k, sizeof(int));

    for (int i = 0; i < k; i++) {
        is_free[i] = true;
    }

    for (int i = 0; i < arrivalSize; i++) {
        long long curr_time = arrival[i];
        long long duration = load[i];

        // Release servers that have completed their tasks
        while (busy->size > 0 && busy->data[1].free_time <= curr_time) {
            HeapNode node = pop(busy);
            is_free[node.server_id] = true;
        }

        // Find available server starting at (i % k)
        int target = -1;
        int start = i % k;
        
        for (int j = 0; j < k; j++) {
            int idx = (start + j) % k;
            if (is_free[idx]) {
                target = idx;
                break;
            }
        }

        // Assign request if an available server is found
        if (target != -1) {
            is_free[target] = false;
            push(busy, curr_time + duration, target);
            count[target]++;
        }
    }

    int max_requests = 0;
    for (int i = 0; i < k; i++) {
        if (count[i] > max_requests) {
            max_requests = count[i];
        }
    }

    int result_count = 0;
    for (int i = 0; i < k; i++) {
        if (count[i] == max_requests) {
            result_count++;
        }
    }

    int* result = (int*)malloc(result_count * sizeof(int));
    int idx = 0;
    for (int i = 0; i < k; i++) {
        if (count[i] == max_requests) {
            result[idx++] = i;
        }
    }

    *returnSize = result_count;

    free(busy->data);
    free(busy);
    free(is_free);
    free(count);

    return result;
}