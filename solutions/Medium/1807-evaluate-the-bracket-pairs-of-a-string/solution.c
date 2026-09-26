// ──────────────────────────────────────────────────
// Problem  : 1807. Evaluate the Bracket Pairs of a String
// Difficulty: Medium
// Tags     : Array, Hash Table, String
// Link     : https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
// Runtime  : 87 ms (beats 83%)
// Memory   : 99564000 (beats 17%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100003

typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
} Node;

unsigned int hash(const char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % TABLE_SIZE;
}

void insert(Node **hashTable, char *key, char *value) {
    unsigned int index = hash(key);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

char* search(Node **hashTable, const char *key) {
    unsigned int index = hash(key);
    Node *curr = hashTable[index];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            return curr->value;
        }
        curr = curr->next;
    }
    return NULL;
}

char* evaluate(char* s, char*** knowledge, int knowledgeSize, int* knowledgeColSize) {
    Node **hashTable = (Node **)calloc(TABLE_SIZE, sizeof(Node *));
    for (int i = 0; i < knowledgeSize; i++) {
        insert(hashTable, knowledge[i][0], knowledge[i][1]);
    }

    int capacity = 200000;
    char *result = (char *)malloc(capacity * sizeof(char));
    int resLen = 0;

    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '(') {
            i++;
            char key[11];
            int keyLen = 0;
            while (s[i] != ')') {
                key[keyLen++] = s[i++];
            }
            key[keyLen] = '\0';
            i++;

            char *val = search(hashTable, key);
            if (val) {
                int valLen = strlen(val);
                memcpy(result + resLen, val, valLen);
                resLen += valLen;
            } else {
                result[resLen++] = '?';
            }
        } else {
            result[resLen++] = s[i++];
        }
    }
    result[resLen] = '\0';

    for (int j = 0; j < TABLE_SIZE; j++) {
        Node *curr = hashTable[j];
        while (curr) {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(hashTable);

    return result;
}