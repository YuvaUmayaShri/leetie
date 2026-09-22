// ──────────────────────────────────────────────────
// Problem  : 447. Number of Boomerangs
// Difficulty: Medium
// Tags     : Array, Hash Table, Math
// Link     : https://leetcode.com/problems/number-of-boomerangs/
// Runtime  : 36 ms (beats 100%)
// Memory   : 10184000 (beats 95%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

typedef struct {
    int key;
    int val;
} HashNode;

typedef struct {
    int capacity;
    HashNode* table;
} HashMap;

static HashMap* createHashMap(int capacity) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->capacity = capacity;
    map->table = (HashNode*)calloc(capacity, sizeof(HashNode));
    return map;
}

static void freeHashMap(HashMap* map) {
    free(map->table);
    free(map);
}

static void clearHashMap(HashMap* map) {
    for (int i = 0; i < map->capacity; i++) {
        map->table[i].key = 0;
        map->table[i].val = 0;
    }
}

static void incrementHashMap(HashMap* map, int key) {
    int idx = abs(key) % map->capacity;
    while (map->table[idx].val > 0 && map->table[idx].key != key) {
        idx = (idx + 1) % map->capacity;
    }
    map->table[idx].key = key;
    map->table[idx].val++;
}

int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize) {
    int total_boomerangs = 0;
    HashMap* map = createHashMap(pointsSize * 2);

    for (int i = 0; i < pointsSize; i++) {
        clearHashMap(map);
        for (int j = 0; j < pointsSize; j++) {
            if (i == j) continue;
            int dx = points[i][0] - points[j][0];
            int dy = points[i][1] - points[j][1];
            int dist = dx * dx + dy * dy;
            incrementHashMap(map, dist);
        }

        for (int k = 0; k < map->capacity; k++) {
            int count = map->table[k].val;
            if (count > 1) {
                total_boomerangs += count * (count - 1);
            }
        }
    }

    freeHashMap(map);
    return total_boomerangs;
}