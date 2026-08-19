// ──────────────────────────────────────────────────
// Problem  : 706. Design HashMap
// Difficulty: Easy
// Tags     : Array, Hash Table, Linked List, Design, Hash Function
// Link     : https://leetcode.com/problems/design-hashmap/
// Runtime  : 7 ms (beats 99%)
// Memory   : 36668000 (beats 85%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

#define BASE 769

typedef struct Node {
    int key;
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* buckets[BASE];
} MyHashMap;

static int hash(int key) {
    return key % BASE;
}

MyHashMap* myHashMapCreate() {
    MyHashMap* obj = (MyHashMap*)calloc(1, sizeof(MyHashMap));
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int h = hash(key);
    Node* curr = obj->buckets[h];
    while (curr) {
        if (curr->key == key) {
            curr->val = value;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->val = value;
    newNode->next = obj->buckets[h];
    obj->buckets[h] = newNode;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int h = hash(key);
    Node* curr = obj->buckets[h];
    while (curr) {
        if (curr->key == key) return curr->val;
        curr = curr->next;
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int h = hash(key);
    Node* curr = obj->buckets[h];
    Node* prev = NULL;
    while (curr) {
        if (curr->key == key) {
            if (prev) {
                prev->next = curr->next;
            } else {
                obj->buckets[h] = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    if (!obj) return;
    for (int i = 0; i < BASE; i++) {
        Node* curr = obj->buckets[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(obj);
}