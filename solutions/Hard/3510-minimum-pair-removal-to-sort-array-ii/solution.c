// ──────────────────────────────────────────────────
// Problem  : 3510. Minimum Pair Removal to Sort Array II
// Difficulty: Hard
// Tags     : Array, Hash Table, Linked List, Heap (Priority Queue), Simulation, Doubly-Linked List, Ordered Set
// Link     : https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8780000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct Node {
    long long val;
    int id;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    long long sum;
    int left_id;
    Node* left_node;
} Pair;

typedef struct {
    Pair* data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (Pair*)malloc(sizeof(Pair) * (capacity + 1));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void pushHeap(MinHeap* h, long long sum, int left_id, Node* left_node) {
    h->size++;
    int i = h->size;
    while (i > 1) {
        int p = i / 2;
        if (h->data[p].sum < sum || (h->data[p].sum == sum && h->data[p].left_id <= left_id)) {
            break;
        }
        h->data[i] = h->data[p];
        i = p;
    }
    h->data[i].sum = sum;
    h->data[i].left_id = left_id;
    h->data[i].left_node = left_node;
}

Pair popHeap(MinHeap* h) {
    Pair top = h->data[1];
    Pair last = h->data[h->size--];
    int i = 1;
    while (i * 2 <= h->size) {
        int child = i * 2;
        if (child + 1 <= h->size) {
            if (h->data[child + 1].sum < h->data[child].sum || 
               (h->data[child + 1].sum == h->data[child].sum && h->data[child + 1].left_id < h->data[child].left_id)) {
                child++;
            }
        }
        if (last.sum < h->data[child].sum || 
           (last.sum == h->data[child].sum && last.left_id <= h->data[child].left_id)) {
            break;
        }
        h->data[i] = h->data[child];
        i = child;
    }
    if (h->size > 0) {
        h->data[i] = last;
    }
    return top;
}

bool isSorted(Node* head) {
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->val > curr->next->val) return false;
        curr = curr->next;
    }
    return true;
}

int minimumPairRemoval(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;

    Node* nodes = (Node*)malloc(sizeof(Node) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        nodes[i].val = nums[i];
        nodes[i].id = i;
        nodes[i].prev = (i > 0) ? &nodes[i - 1] : NULL;
        nodes[i].next = (i < numsSize - 1) ? &nodes[i + 1] : NULL;
    }

    MinHeap* heap = createHeap(numsSize * 4);

    for (int i = 0; i < numsSize - 1; i++) {
        pushHeap(heap, nodes[i].val + nodes[i + 1].val, nodes[i].id, &nodes[i]);
    }

    int ops = 0;
    Node* head = &nodes[0];

    while (!isSorted(head)) {
        Pair p = popHeap(heap);
        Node* u = p.left_node;
        Node* v = u->next;

        if (!v || u->val + v->val != p.sum) {
            continue;
        }

        Node* prev = u->prev;
        Node* next = v->next;

        u->val = p.sum;
        u->next = next;
        if (next) next->prev = u;

        if (prev) {
            pushHeap(heap, prev->val + u->val, prev->id, prev);
        }
        if (next) {
            pushHeap(heap, u->val + next->val, u->id, u);
        }

        ops++;
    }

    free(nodes);
    free(heap->data);
    free(heap);

    return ops;
}