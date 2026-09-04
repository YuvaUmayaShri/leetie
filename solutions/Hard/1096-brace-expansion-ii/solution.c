// ──────────────────────────────────────────────────
// Problem  : 1096. Brace Expansion II
// Difficulty: Hard
// Tags     : Hash Table, String, Backtracking, Stack, Breadth-First Search, Sorting
// Link     : https://leetcode.com/problems/brace-expansion-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8888000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

typedef struct {
    char** data;
    int size;
    int capacity;
} Set;

Set* createSet() {
    Set* set = (Set*)malloc(sizeof(Set));
    set->capacity = 8;
    set->size = 0;
    set->data = (char**)malloc(set->capacity * sizeof(char*));
    return set;
}

void addToSet(Set* set, const char* str) {
    for (int i = 0; i < set->size; i++) {
        if (strcmp(set->data[i], str) == 0) return;
    }
    if (set->size == set->capacity) {
        set->capacity *= 2;
        set->data = (char**)realloc(set->data, set->capacity * sizeof(char*));
    }
    set->data[set->size++] = strdup(str);
}

void freeSet(Set* set) {
    for (int i = 0; i < set->size; i++) {
        free(set->data[i]);
    }
    free(set->data);
    free(set);
}

Set* parseExpr(const char* expr, int* index);

Set* parseGroup(const char* expr, int* index) {
    Set* groupSet = createSet();

    while (expr[*index] && expr[*index] != '}' && expr[*index] != ',') {
        Set* nextSet;
        if (expr[*index] == '{') {
            (*index)++;
            nextSet = parseExpr(expr, index);
            if (expr[*index] == '}') (*index)++;
        } else {
            int start = *index;
            while (expr[*index] >= 'a' && expr[*index] <= 'z') {
                (*index)++;
            }
            int len = *index - start;
            char* word = (char*)malloc(len + 1);
            strncpy(word, expr + start, len);
            word[len] = '\0';

            nextSet = createSet();
            addToSet(nextSet, word);
            free(word);
        }

        if (groupSet->size == 0) {
            for (int i = 0; i < nextSet->size; i++) {
                addToSet(groupSet, nextSet->data[i]);
            }
        } else {
            Set* temp = createSet();
            for (int i = 0; i < groupSet->size; i++) {
                for (int j = 0; j < nextSet->size; j++) {
                    char concatenated[128];
                    snprintf(concatenated, sizeof(concatenated), "%s%s", groupSet->data[i], nextSet->data[j]);
                    addToSet(temp, concatenated);
                }
            }
            freeSet(groupSet);
            groupSet = temp;
        }
        freeSet(nextSet);
    }

    return groupSet;
}

Set* parseExpr(const char* expr, int* index) {
    Set* resultSet = createSet();

    while (expr[*index] && expr[*index] != '}') {
        Set* groupSet = parseGroup(expr, index);
        for (int i = 0; i < groupSet->size; i++) {
            addToSet(resultSet, groupSet->data[i]);
        }
        freeSet(groupSet);

        if (expr[*index] == ',') {
            (*index)++;
        }
    }

    return resultSet;
}

char** braceExpansionII(char* expression, int* returnSize) {
    int index = 0;
    Set* resultSet = parseExpr(expression, &index);

    qsort(resultSet->data, resultSet->size, sizeof(char*), compareStrings);

    *returnSize = resultSet->size;
    char** result = resultSet->data;

    free(resultSet);
    return result;
}