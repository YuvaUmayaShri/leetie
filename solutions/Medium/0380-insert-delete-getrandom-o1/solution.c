// ──────────────────────────────────────────────────
// Problem  : 380. Insert Delete GetRandom O(1)
// Difficulty: Medium
// Tags     : Array, Hash Table, Math, Design, Randomized
// Link     : https://leetcode.com/problems/insert-delete-getrandom-o1/
// Runtime  : 0 ms (beats 0%)
// Memory   : 9008000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int key;
    int index;
} HashNode;

typedef struct {
    int* nums;
    int numsSize;
    int numsCapacity;
    HashNode** table;
    int tableSize;
} RandomizedSet;

static int hash(int key, int size) {
    unsigned int ukey = (unsigned int)key;
    return ukey % size;
}

static HashNode* findNode(RandomizedSet* obj, int key) {
    int idx = hash(key, obj->tableSize);
    HashNode* curr = obj->table[idx];
    while (curr != NULL) {
        if (curr->key == key) {
            return curr;
        }
        idx = (idx + 1) % obj->tableSize;
        curr = obj->table[idx];
    }
    return NULL;
}

static void insertNode(RandomizedSet* obj, int key, int index) {
    int idx = hash(key, obj->tableSize);
    while (obj->table[idx] != NULL && obj->table[idx]->key != key) {
        idx = (idx + 1) % obj->tableSize;
    }
    if (obj->table[idx] == NULL) {
        obj->table[idx] = (HashNode*)malloc(sizeof(HashNode));
    }
    obj->table[idx]->key = key;
    obj->table[idx]->index = index;
}

static void removeNode(RandomizedSet* obj, int key) {
    int idx = hash(key, obj->tableSize);
    while (obj->table[idx] != NULL && obj->table[idx]->key != key) {
        idx = (idx + 1) % obj->tableSize;
    }
    if (obj->table[idx] == NULL) return;

    free(obj->table[idx]);
    obj->table[idx] = NULL;

    idx = (idx + 1) % obj->tableSize;
    while (obj->table[idx] != NULL) {
        HashNode* nodeToRehash = obj->table[idx];
        obj->table[idx] = NULL;
        insertNode(obj, nodeToRehash->key, nodeToRehash->index);
        free(nodeToRehash);
        idx = (idx + 1) % obj->tableSize;
    }
}

RandomizedSet* randomizedSetCreate() {
    RandomizedSet* obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    obj->numsCapacity = 100000;
    obj->numsSize = 0;
    obj->nums = (int*)malloc(obj->numsCapacity * sizeof(int));
    
    obj->tableSize = 200003;
    obj->table = (HashNode**)calloc(obj->tableSize, sizeof(HashNode*));
    return obj;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    HashNode* node = findNode(obj, val);
    if (node != NULL) {
        return false;
    }
    obj->nums[obj->numsSize] = val;
    insertNode(obj, val, obj->numsSize);
    obj->numsSize++;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    HashNode* node = findNode(obj, val);
    if (node == NULL) {
        return false;
    }
    int idx = node->index;
    int lastVal = obj->nums[obj->numsSize - 1];
    
    obj->nums[idx] = lastVal;
    insertNode(obj, lastVal, idx);
    
    removeNode(obj, val);
    obj->numsSize--;
    return true;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    int randomIndex = rand() % obj->numsSize;
    return obj->nums[randomIndex];
}

void randomizedSetFree(RandomizedSet* obj) {
    for (int i = 0; i < obj->tableSize; i++) {
        if (obj->table[i] != NULL) {
            free(obj->table[i]);
        }
    }
    free(obj->table);
    free(obj->nums);
    free(obj);
}