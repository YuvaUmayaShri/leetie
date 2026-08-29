// ──────────────────────────────────────────────────
// Problem  : 1046. Last Stone Weight
// Difficulty: Easy
// Tags     : Array, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/last-stone-weight/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8756000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int lastStoneWeight(int* stones, int stonesSize) {
    while (stonesSize > 1) {
        qsort(stones, stonesSize, sizeof(int), compare);
        
        int y = stones[stonesSize - 1];
        int x = stones[stonesSize - 2];
        
        if (x == y) {
            stonesSize -= 2;
        } else {
            stones[stonesSize - 2] = y - x;
            stonesSize -= 1;
        }
    }
    
    return stonesSize == 1 ? stones[0] : 0;
}