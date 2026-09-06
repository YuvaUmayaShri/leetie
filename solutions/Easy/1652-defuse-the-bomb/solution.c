// ──────────────────────────────────────────────────
// Problem  : 1652. Defuse the Bomb
// Difficulty: Easy
// Tags     : Array, Sliding Window
// Link     : https://leetcode.com/problems/defuse-the-bomb/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10964000 (beats 33%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    int* result = (int*)malloc(codeSize * sizeof(int));
    *returnSize = codeSize;

    if (k == 0) {
        for (int i = 0; i < codeSize; i++) {
            result[i] = 0;
        }
        return result;
    }

    int start, end;
    if (k > 0) {
        start = 1;
        end = k;
    } else {
        start = codeSize + k;
        end = codeSize - 1;
    }

    int currentSum = 0;
    for (int i = start; i <= end; i++) {
        currentSum += code[i % codeSize];
    }

    for (int i = 0; i < codeSize; i++) {
        result[i] = currentSum;
        currentSum -= code[(start + i) % codeSize];
        currentSum += code[(end + i + 1) % codeSize];
    }

    return result;
}