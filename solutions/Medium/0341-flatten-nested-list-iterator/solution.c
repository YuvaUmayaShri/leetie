// ──────────────────────────────────────────────────
// Problem  : 341. Flatten Nested List Iterator
// Difficulty: Medium
// Tags     : Stack, Tree, Depth-First Search, Design, Queue, Iterator
// Link     : https://leetcode.com/problems/flatten-nested-list-iterator/
// Runtime  : 13 ms (beats 57%)
// Memory   : 18044000 (beats 39%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 *
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 * int NestedIntegerGetInteger(struct NestedInteger *);
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 * int NestedIntegerGetListSize(struct NestedInteger *);
 */

struct NestedIterator {
    int* data;
    int index;
    int size;
    int capacity;
};

void flatten(struct NestedInteger** nestedList, int nestedListSize, struct NestedIterator* iter) {
    for (int i = 0; i < nestedListSize; i++) {
        if (NestedIntegerIsInteger(nestedList[i])) {
            if (iter->size >= iter->capacity) {
                iter->capacity *= 2;
                iter->data = (int*)realloc(iter->data, iter->capacity * sizeof(int));
            }
            iter->data[iter->size++] = NestedIntegerGetInteger(nestedList[i]);
        } else {
            flatten(NestedIntegerGetList(nestedList[i]), NestedIntegerGetListSize(nestedList[i]), iter);
        }
    }
}

struct NestedIterator *nestedIterCreate(struct NestedInteger **nestedList, int nestedListSize) {
    struct NestedIterator* iter = (struct NestedIterator*)malloc(sizeof(struct NestedIterator));
    iter->capacity = 10000;
    iter->data = (int*)malloc(iter->capacity * sizeof(int));
    iter->index = 0;
    iter->size = 0;
    
    flatten(nestedList, nestedListSize, iter);
    return iter;
}

bool nestedIterHasNext(struct NestedIterator *iter) {
    return iter->index < iter->size;
}

int nestedIterNext(struct NestedIterator *iter) {
    return iter->data[iter->index++];
}

void nestedIterFree(struct NestedIterator *iter) {
    free(iter->data);
    free(iter);
}