// ──────────────────────────────────────────────────
// Problem  : 950. Reveal Cards In Increasing Order
// Difficulty: Medium
// Tags     : Array, Queue, Sorting, Simulation
// Link     : https://leetcode.com/problems/reveal-cards-in-increasing-order/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12364000 (beats 36%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
    qsort(deck, deckSize, sizeof(int), compare);

    int* result = (int*)malloc(deckSize * sizeof(int));
    int* indexQueue = (int*)malloc(2 * deckSize * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < deckSize; i++) {
        indexQueue[rear++] = i;
    }

    for (int i = 0; i < deckSize; i++) {
        result[indexQueue[front++]] = deck[i];
        if (front < rear) {
            indexQueue[rear++] = indexQueue[front++];
        }
    }

    free(indexQueue);
    *returnSize = deckSize;
    return result;
}