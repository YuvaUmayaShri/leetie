// ──────────────────────────────────────────────────
// Problem  : 1331. Rank Transform of an Array
// Difficulty: Easy
// Tags     : Array, Hash Table, Sorting
// Link     : https://leetcode.com/problems/rank-transform-of-an-array/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8324000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x > y) - (x < y);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* arrayRankTransform(
    int* arr,
    int arrSize,
    int* returnSize
) {
    int* sortedArray = malloc(arrSize * sizeof(int));
    int* result = malloc(arrSize * sizeof(int));

    for (int i = 0; i < arrSize; i++) {
        sortedArray[i] = arr[i];
    }

    qsort(sortedArray, arrSize, sizeof(int), compare);

    int uniqueSize = 0;

    for (int i = 0; i < arrSize; i++) {
        if (i == 0 || sortedArray[i] != sortedArray[i - 1]) {
            sortedArray[uniqueSize++] = sortedArray[i];
        }
    }

    for (int i = 0; i < arrSize; i++) {
        int left = 0;
        int right = uniqueSize - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (sortedArray[mid] == arr[i]) {
                result[i] = mid + 1;
                break;
            }

            if (sortedArray[mid] < arr[i]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    free(sortedArray);

    *returnSize = arrSize;
    return result;
}