// ──────────────────────────────────────────────────
// Problem  : 1036. Escape a Large Maze
// Difficulty: Hard
// Tags     : Array, Hash Table, Depth-First Search, Breadth-First Search, Bidirectional Search
// Link     : https://leetcode.com/problems/escape-a-large-maze/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8976000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <stdlib.h>

#define MAX_VISITED 20000

typedef struct {
    long long key;
    int val;
} HashItem;

typedef struct {
    HashItem* data;
    int capacity;
} HashSet;

HashSet* createSet(int capacity) {
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));
    set->capacity = capacity;
    set->data = (HashItem*)calloc(capacity, sizeof(HashItem));
    return set;
}

void freeSet(HashSet* set) {
    free(set->data);
    free(set);
}

int hash(long long key, int capacity) {
    long long h = key % capacity;
    if (h < 0) h += capacity;
    return (int)h;
}

void insertSet(HashSet* set, long long key) {
    int idx = hash(key, set->capacity);
    while (set->data[idx].val == 1) {
        if (set->data[idx].key == key) return;
        idx = (idx + 1) % set->capacity;
    }
    set->data[idx].key = key;
    set->data[idx].val = 1;
}

bool containsSet(HashSet* set, long long key) {
    int idx = hash(key, set->capacity);
    while (set->data[idx].val == 1) {
        if (set->data[idx].key == key) return true;
        idx = (idx + 1) % set->capacity;
    }
    return false;
}

int bfs(int** blocked, int blockedSize, int* start, int* target, HashSet* blockedSet) {
    HashSet* visited = createSet(60000);
    
    long long startKey = ((long long)start[0] << 30) | start[1];
    long long targetKey = ((long long)target[0] << 30) | target[1];
    
    insertSet(visited, startKey);
    
    long long queue[MAX_VISITED + 5];
    int head = 0, tail = 0;
    queue[tail++] = startKey;
    
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int count = 0;

    while (head < tail && count <= MAX_VISITED) {
        long long curr = queue[head++];
        count++;

        if (curr == targetKey) {
            freeSet(visited);
            return 1;
        }

        int r = curr >> 30;
        int c = curr & 0x3FFFFFFF;

        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];

            if (nr >= 0 && nr < 1000000 && nc >= 0 && nc < 1000000) {
                long long nxtKey = ((long long)nr << 30) | nc;
                if (!containsSet(blockedSet, nxtKey) && !containsSet(visited, nxtKey)) {
                    insertSet(visited, nxtKey);
                    if (tail < MAX_VISITED + 4) {
                        queue[tail++] = nxtKey;
                    }
                }
            }
        }
    }

    freeSet(visited);
    return count > MAX_VISITED ? 2 : 0;
}

bool isEscapePossible(int** blocked, int blockedSize, int* blockedColSize, int* source, int sourceSize, int* target, int targetSize) {
    if (blockedSize < 2) return true;

    HashSet* blockedSet = createSet(blockedSize * 3 + 10);
    for (int i = 0; i < blockedSize; i++) {
        long long key = ((long long)blocked[i][0] << 30) | blocked[i][1];
        insertSet(blockedSet, key);
    }

    int res1 = bfs(blocked, blockedSize, source, target, blockedSet);
    if (res1 == 0) {
        freeSet(blockedSet);
        return false;
    }
    if (res1 == 1) {
        freeSet(blockedSet);
        return true;
    }

    int res2 = bfs(blocked, blockedSize, target, source, blockedSet);
    freeSet(blockedSet);

    return res2 != 0;
}