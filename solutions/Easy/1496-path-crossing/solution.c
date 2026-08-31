// ──────────────────────────────────────────────────
// Problem  : 1496. Path Crossing
// Difficulty: Easy
// Tags     : Hash Table, String
// Link     : https://leetcode.com/problems/path-crossing/
// Runtime  : 3 ms (beats 25%)
// Memory   : 9100000 (beats 78%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <stdlib.h>

#define HASH_SIZE 20011

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

int getHash(int x, int y) {
    // Offset negative values and combine x and y into a single hash key
    unsigned int hash = ((unsigned int)(x + 10000) * 20001) + (unsigned int)(y + 10000);
    return hash % HASH_SIZE;
}

bool contains(Node** hashTable, int x, int y) {
    int hash = getHash(x, y);
    Node* curr = hashTable[hash];
    while (curr != NULL) {
        if (curr->x == x && curr->y == y) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void insert(Node** hashTable, int x, int y) {
    int hash = getHash(x, y);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = hashTable[hash];
    hashTable[hash] = newNode;
}

bool isPathCrossing(char* path) {
    Node* hashTable[HASH_SIZE] = {NULL};

    int x = 0;
    int y = 0;
    insert(hashTable, x, y);

    for (int i = 0; path[i] != '\0'; i++) {
        switch (path[i]) {
            case 'N': y++; break;
            case 'S': y--; break;
            case 'E': x++; break;
            case 'W': x--; break;
        }

        if (contains(hashTable, x, y)) {
            // Free allocated memory before returning
            for (int j = 0; j < HASH_SIZE; j++) {
                Node* curr = hashTable[j];
                while (curr) {
                    Node* temp = curr;
                    curr = curr->next;
                    free(temp);
                }
            }
            return true;
        }

        insert(hashTable, x, y);
    }

    // Free allocated memory
    for (int j = 0; j < HASH_SIZE; j++) {
        Node* curr = hashTable[j];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    return false;
}