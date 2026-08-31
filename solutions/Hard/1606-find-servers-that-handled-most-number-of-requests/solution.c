// ──────────────────────────────────────────────────
// Problem  : 1606. Find Servers That Handled Most Number of Requests
// Difficulty: Hard
// Tags     : Array, Heap (Priority Queue), Simulation, Ordered Set
// Link     : https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
// Runtime  : 2 ms (beats 0%)
// Memory   : 8672000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    long long free_time;
    int server_id;
} BusyNode;

typedef struct {
    BusyNode* data;
    int size;
} BusyHeap;

BusyHeap* createBusyHeap(int capacity) {
    BusyHeap* heap = (BusyHeap*)malloc(sizeof(BusyHeap));
    heap->data = (BusyNode*)malloc((capacity + 1) * sizeof(BusyNode));
    heap->size = 0;
    return heap;
}

void pushBusy(BusyHeap* heap, long long free_time, int server_id) {
    heap->size++;
    int i = heap->size;
    heap->data[i].free_time = free_time;
    heap->data[i].server_id = server_id;
    while (i > 1 && heap->data[i].free_time < heap->data[i / 2].free_time) {
        BusyNode temp = heap->data[i];
        heap->data[i] = heap->data[i / 2];
        heap->data[i / 2] = temp;
        i /= 2;
    }
}

BusyNode popBusy(BusyHeap* heap) {
    BusyNode top = heap->data[1];
    heap->data[1] = heap->data[heap->size--];
    int i = 1;
    while (i * 2 <= heap->size) {
        int smallest = i * 2;
        if (smallest + 1 <= heap->size && heap->data[smallest + 1].free_time < heap->data[smallest].free_time) {
            smallest++;
        }
        if (heap->data[i].free_time <= heap->data[smallest].free_time) break;
        BusyNode temp = heap->data[i];
        heap->data[i] = heap->data[smallest];
        heap->data[smallest] = temp;
        i = smallest;
    }
    return top;
}

typedef struct {
    int* data;
    int size;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (int*)malloc((capacity + 1) * sizeof(int));
    heap->size = 0;
    return heap;
}

void pushMin(MinHeap* heap, int val) {
    heap->size++;
    int i = heap->size;
    heap->data[i] = val;
    while (i > 1 && heap->data[i] < heap->data[i / 2]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[i / 2];
        heap->data[i / 2] = temp;
        i /= 2;
    }
}

int popMin(MinHeap* heap) {
    int top = heap->data[1];
    heap->data[1] = heap->data[heap->size--];
    int i = 1;
    while (i * 2 <= heap->size) {
        int smallest = i * 2;
        if (smallest + 1 <= heap->size && heap->data[smallest + 1] < heap->data[smallest]) {
            smallest++;
        }
        if (heap->data[i] <= heap->data[smallest]) break;
        int temp = heap->data[i];
        heap->data[i] = heap->data[smallest];
        heap->data[smallest] = temp;
        i = smallest;
    }
    return top;
}

int* busiestServers(int k, int* arrival, int arrivalSize, int* load, int loadSize, int* returnSize) {
    BusyHeap* busy = createBusyHeap(k);
    MinHeap* avail_after = createMinHeap(k);
    MinHeap* avail_before = createMinHeap(k);
    int* count = (int*)calloc(k, sizeof(int));

    for (int i = 0; i < k; i++) {
        pushMin(avail_after, i);
    }

    for (int i = 0; i < arrivalSize; i++) {
        long long curr_time = arrival[i];
        long long duration = load[i];
        int target_start = i % k;

        // Release servers finishing before or at curr_time
        while (busy->size > 0 && busy->data[1].free_time <= curr_time) {
            BusyNode node = popBusy(busy);
            if (node.server_id >= target_start) {
                pushMin(avail_after, node.server_id);
            } else {
                pushMin(avail_before, node.server_id);
            }
        }

        // Shift servers < target_start from avail_after to avail_before
        while (avail_after->size > 0 && avail_after->data[1] < target_start) {
            pushMin(avail_before, popMin(avail_after));
        }

        int selected_server = -1;
        if (avail_after->size > 0) {
            selected_server = popMin(avail_after);
        } else if (avail_before->size > 0) {
            selected_server = popMin(avail_before);
        }

        if (selected_server != -1) {
            count[selected_server]++;
            pushBusy(busy, curr_time + duration, selected_server);
        }
    }

    int max_requests = 0;
    for (int i = 0; i < k; i++) {
        if (count[i] > max_requests) max_requests = count[i];
    }

    int result_count = 0;
    for (int i = 0; i < k; i++) {
        if (count[i] == max_requests) result_count++;
    }

    int* result = (int*)malloc(result_count * sizeof(int));
    int idx = 0;
    for (int i = 0; i < k; i++) {
        if (count[i] == max_requests) result[idx++] = i;
    }

    *returnSize = result_count;

    free(busy->data); free(busy);
    free(avail_after->data); free(avail_after);
    free(avail_before->data); free(avail_before);
    free(count);

    return result;
}