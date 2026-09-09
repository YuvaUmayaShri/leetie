// ──────────────────────────────────────────────────
// Problem  : 1670. Design Front Middle Back Queue
// Difficulty: Medium
// Tags     : Array, Linked List, Design, Queue, Doubly-Linked List, Data Stream
// Link     : https://leetcode.com/problems/design-front-middle-back-queue/
// Runtime  : 17 ms (beats 8%)
// Memory   : 20864000 (beats 58%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Deque {
    Node* head;
    Node* tail;
    int size;
} Deque;

Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->head = NULL;
    dq->tail = NULL;
    dq->size = 0;
    return dq;
}

void pushFrontDeque(Deque* dq, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->prev = NULL;
    node->next = dq->head;
    if (dq->size == 0) {
        dq->head = node;
        dq->tail = node;
    } else {
        dq->head->prev = node;
        dq->head = node;
    }
    dq->size++;
}

void pushBackDeque(Deque* dq, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->prev = dq->tail;
    if (dq->size == 0) {
        dq->head = node;
        dq->tail = node;
    } else {
        dq->tail->next = node;
        dq->tail = node;
    }
    dq->size++;
}

int popFrontDeque(Deque* dq) {
    if (dq->size == 0) return -1;
    Node* node = dq->head;
    int val = node->val;
    dq->head = dq->head->next;
    if (dq->head) {
        dq->head->prev = NULL;
    } else {
        dq->tail = NULL;
    }
    free(node);
    dq->size--;
    return val;
}

int popBackDeque(Deque* dq) {
    if (dq->size == 0) return -1;
    Node* node = dq->tail;
    int val = node->val;
    dq->tail = dq->tail->prev;
    if (dq->tail) {
        dq->tail->next = NULL;
    } else {
        dq->head = NULL;
    }
    free(node);
    dq->size--;
    return val;
}

typedef struct {
    Deque* left;
    Deque* right;
} FrontMiddleBackQueue;

void rebalance(FrontMiddleBackQueue* obj) {
    if (obj->left->size > obj->right->size) {
        pushFrontDeque(obj->right, popBackDeque(obj->left));
    } else if (obj->right->size > obj->left->size + 1) {
        pushBackDeque(obj->left, popFrontDeque(obj->right));
    }
}

FrontMiddleBackQueue* frontMiddleBackQueueCreate() {
    FrontMiddleBackQueue* obj = (FrontMiddleBackQueue*)malloc(sizeof(FrontMiddleBackQueue));
    obj->left = createDeque();
    obj->right = createDeque();
    return obj;
}

void frontMiddleBackQueuePushFront(FrontMiddleBackQueue* obj, int val) {
    pushFrontDeque(obj->left, val);
    rebalance(obj);
}

void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue* obj, int val) {
    if (obj->left->size < obj->right->size) {
        pushBackDeque(obj->left, val);
    } else {
        pushFrontDeque(obj->right, val);
    }
}

void frontMiddleBackQueuePushBack(FrontMiddleBackQueue* obj, int val) {
    pushBackDeque(obj->right, val);
    rebalance(obj);
}

int frontMiddleBackQueuePopFront(FrontMiddleBackQueue* obj) {
    if (obj->left->size == 0 && obj->right->size == 0) return -1;
    int val;
    if (obj->left->size > 0) {
        val = popFrontDeque(obj->left);
    } else {
        val = popFrontDeque(obj->right);
    }
    rebalance(obj);
    return val;
}

int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue* obj) {
    if (obj->left->size == 0 && obj->right->size == 0) return -1;
    int val;
    if (obj->left->size == obj->right->size) {
        val = popBackDeque(obj->left);
    } else {
        val = popFrontDeque(obj->right);
    }
    rebalance(obj);
    return val;
}

int frontMiddleBackQueuePopBack(FrontMiddleBackQueue* obj) {
    if (obj->left->size == 0 && obj->right->size == 0) return -1;
    int val = popBackDeque(obj->right);
    rebalance(obj);
    return val;
}

void freeDeque(Deque* dq) {
    Node* curr = dq->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(dq);
}

void frontMiddleBackQueueFree(FrontMiddleBackQueue* obj) {
    if (!obj) return;
    freeDeque(obj->left);
    freeDeque(obj->right);
    free(obj);
}