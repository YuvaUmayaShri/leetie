// ──────────────────────────────────────────────────
// Problem  : 898. Bitwise ORs of Subarrays
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Bit Manipulation
// Link     : https://leetcode.com/problems/bitwise-ors-of-subarrays/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8712000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int subarrayBitwiseORs(int* arr, int arrSize) {
    int* res = (int*)malloc(sizeof(int) * arrSize * 32);
    int resSize = 0;

    int cur[32];
    int curSize = 0;

    for (int i = 0; i < arrSize; i++) {
        int next[32];
        int nextSize = 0;

        next[nextSize++] = arr[i];
        res[resSize++] = arr[i];

        for (int j = 0; j < curSize; j++) {
            int val = cur[j] | arr[i];
            if (next[nextSize - 1] != val) {
                next[nextSize++] = val;
                res[resSize++] = val;
            }
        }

        for (int j = 0; j < nextSize; j++) {
            cur[j] = next[j];
        }
        curSize = nextSize;
    }

    qsort(res, resSize, sizeof(int), cmp);

    int ans = 0;
    for (int i = 0; i < resSize; i++) {
        if (i == 0 || res[i] != res[i - 1]) {
            ans++;
        }
    }

    free(res);
    return ans;
}