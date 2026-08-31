// ──────────────────────────────────────────────────
// Problem  : 1606. Find Servers That Handled Most Number of Requests
// Difficulty: Hard
// Tags     : Array, Heap (Priority Queue), Simulation, Ordered Set
// Link     : https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8744000 (beats 0%)
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

// Tree structure for O(log k) range minimum query of available servers
void updateTree(int* tree, int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = start + (end - start) / 2;
    if (idx <= mid) updateTree(tree, 2 * node, start, mid, idx, val);
    else updateTree(tree, 2 * node + 1, mid + 1, end, idx, val);
    tree[node] = (tree[2 * node] != -1) ? tree[2 * node] : tree[2 * node + 1];
}

int queryTree(int* tree, int node, int start, int end, int l, int r) {
    if (r < start || end < l || tree[node] == -1) return -1;
    if (l <= start && end <= r) return tree[node];
    int mid = start + (end - start) / 2;
    int left_ans = queryTree(tree, 2 * node, start, mid, l, r);
    if (left_ans != -1) return left_ans;
    return queryTree(tree, 2 * node + 1, mid + 1, end, l, r);
}

int* busiestServers(int k, int* arrival, int arrivalSize, int* load, int loadSize, int* returnSize) {
    BusyHeap* busy = createBusyHeap(k);
    int* tree = (int*)malloc(4 * k * sizeof(int));
    int* count = (int*)calloc(k, sizeof(int));

    for (int i = 0; i < 4 * k; i++) tree[i] = -1;
    for (int i = 0; i < k; i++) updateTree(tree, 1, 0, k - 1, i, i);

    for (int i = 0; i < arrivalSize; i++) {
        long long curr_time = arrival[i];
        long long duration = load[i];
        int target_start = i % k;

        // Free completed servers
        while (busy->size > 0 && busy->data[1].free_time <= curr_time) {
            BusyNode node = popBusy(busy);
            updateTree(tree, 1, 0, k - 1, node.server_id, node.server_id);
        }

        // Query available server in range [target_start, k - 1]
        int selected = queryTree(tree, 1, 0, k - 1, target_start, k - 1);
        
        // Wrap around to range [0, target_start - 1] if needed
        if (selected == -1 && target_start > 0) {
            selected = queryTree(tree, 1, 0, k - 1, 0, target_start - 1);
        }

        if (selected != -1) {
            count[selected]++;
            updateTree(tree, 1, 0, k - 1, selected, -1);
            pushBusy(busy, curr_time + duration, selected);
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
    free(tree);
    free(count);

    return result;
}