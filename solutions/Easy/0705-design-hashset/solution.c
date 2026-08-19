// ──────────────────────────────────────────────────
// Problem  : 705. Design HashSet
// Difficulty: Easy
// Tags     : Array, Hash Table, Linked List, Design, Hash Function
// Link     : https://leetcode.com/problems/design-hashset/
// Runtime  : 8 ms (beats 86%)
// Memory   : 32244000 (beats 74%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <stdlib.h>

#define BASE 769

typedef struct Node {
    int key;
    struct Node* next;
} Node;

typedef struct {
    Node* buckets[BASE];
} MyHashSet;

static int hash(int key) {
    return key % BASE;
}

MyHashSet* myHashSetCreate() {
    MyHashSet* obj = (MyHashSet*)calloc(1, sizeof(MyHashSet));
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int h = hash(key);
    Node* curr = obj->buckets[h];
    while (curr) {
        if (curr->key == key) return;
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = obj->buckets[h];
    obj->buckets[h] = newNode;
}

void myHashSetRemove(MyHashSet* obj, int key) {
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

bool myHashSetContains(MyHashSet* obj, int key) {
    int h = hash(key);
    Node* curr = obj->buckets[h];
    while (curr) {
        if (curr->key == key) return true;
        curr = curr->next;
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
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