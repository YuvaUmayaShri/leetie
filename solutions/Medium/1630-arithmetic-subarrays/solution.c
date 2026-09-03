// ──────────────────────────────────────────────────
// Problem  : 1630. Arithmetic Subarrays
// Difficulty: Medium
// Tags     : Array, Hash Table, Sorting
// Link     : https://leetcode.com/problems/arithmetic-subarrays/
// Runtime  : 39 ms (beats 0%)
// Memory   : 17792000 (beats 14%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) {
    *returnSize = lSize;
    bool* ans = (bool*)malloc(lSize * sizeof(bool));

    for (int i = 0; i < lSize; i++) {
        int start = l[i];
        int end = r[i];
        int len = end - start + 1;

        int* sub = (int*)malloc(len * sizeof(int));
        for (int j = 0; j < len; j++) {
            sub[j] = nums[start + j];
        }

        qsort(sub, len, sizeof(int), compare);

        bool isArithmetic = true;
        int diff = sub[1] - sub[0];
        for (int j = 2; j < len; j++) {
            if (sub[j] - sub[j - 1] != diff) {
                isArithmetic = false;
                break;
            }
        }

        ans[i] = isArithmetic;
        free(sub);
    }

    return ans;
}