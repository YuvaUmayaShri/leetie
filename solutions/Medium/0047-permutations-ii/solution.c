// ──────────────────────────────────────────────────
// Problem  : 47. Permutations II
// Difficulty: Medium
// Tags     : Array, Backtracking, Sorting
// Link     : https://leetcode.com/problems/permutations-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8604000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void backtrack(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** result, int* current, int* used, int depth) {
    if (depth == numsSize) {
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = current[i];
        }
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

        used[i] = 1;
        current[depth] = nums[i];
        backtrack(nums, numsSize, returnSize, returnColumnSizes, result, current, used, depth + 1);
        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int maxCapacity = 1;
    for (int i = 1; i <= numsSize; i++) {
        maxCapacity *= i;
    }

    int** result = (int**)malloc(maxCapacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxCapacity * sizeof(int));
    *returnSize = 0;

    int* current = (int*)malloc(numsSize * sizeof(int));
    int* used = (int*)calloc(numsSize, sizeof(int));

    backtrack(nums, numsSize, returnSize, returnColumnSizes, result, current, used, 0);

    free(current);
    free(used);

    return result;
}