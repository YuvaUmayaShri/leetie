// ──────────────────────────────────────────────────
// Problem  : 57. Insert Interval
// Difficulty: Medium
// Tags     : Array
// Link     : https://leetcode.com/problems/insert-interval/
// Runtime  : 0 ms (beats 100%)
// Memory   : 14464000 (beats 69%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((intervalsSize + 1) * sizeof(int));
    *returnSize = 0;

    int i = 0;

    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[*returnSize] = (int*)malloc(2 * sizeof(int));
        result[*returnSize][0] = intervals[i][0];
        result[*returnSize][1] = intervals[i][1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        i++;
    }

    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        if (intervals[i][0] < newInterval[0]) {
            newInterval[0] = intervals[i][0];
        }
        if (intervals[i][1] > newInterval[1]) {
            newInterval[1] = intervals[i][1];
        }
        i++;
    }

    result[*returnSize] = (int*)malloc(2 * sizeof(int));
    result[*returnSize][0] = newInterval[0];
    result[*returnSize][1] = newInterval[1];
    (*returnColumnSizes)[*returnSize] = 2;
    (*returnSize)++;

    while (i < intervalsSize) {
        result[*returnSize] = (int*)malloc(2 * sizeof(int));
        result[*returnSize][0] = intervals[i][0];
        result[*returnSize][1] = intervals[i][1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        i++;
    }

    return result;
}