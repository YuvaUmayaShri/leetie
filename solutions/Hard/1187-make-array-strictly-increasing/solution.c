// ──────────────────────────────────────────────────
// Problem  : 1187. Make Array Strictly Increasing
// Difficulty: Hard
// Tags     : Array, Binary Search, Dynamic Programming, Sorting, Longest Increasing Subsequence
// Link     : https://leetcode.com/problems/make-array-strictly-increasing/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8612000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int bisectRight(int* arr, int size, int target) {
    int low = 0, high = size;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int makeArrayIncreasing(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    qsort(arr2, arr2Size, sizeof(int), compare);
    
    int uniqueSize = 0;
    for (int i = 0; i < arr2Size; i++) {
        if (i == 0 || arr2[i] != arr2[i - 1]) {
            arr2[uniqueSize++] = arr2[i];
        }
    }

    int* dp = (int*)malloc((arr1Size + 1) * sizeof(int));
    int* dpVal = (int*)malloc((arr1Size + 1) * sizeof(int));

    for (int i = 0; i <= arr1Size; i++) {
        dp[i] = 1e9;
        dpVal[i] = 1e9;
    }

    dp[0] = 0;
    dpVal[0] = -1;

    for (int i = 0; i < arr1Size; i++) {
        int* nextDp = (int*)malloc((arr1Size + 1) * sizeof(int));
        int* nextDpVal = (int*)malloc((arr1Size + 1) * sizeof(int));

        for (int k = 0; k <= arr1Size; k++) {
            nextDp[k] = 1e9;
            nextDpVal[k] = 1e9;
        }

        for (int j = 0; j <= i; j++) {
            if (dp[j] == 1e9) continue;

            int prev = dpVal[j];

            if (arr1[i] > prev) {
                if (dp[j] < nextDp[j] || (dp[j] == nextDp[j] && arr1[i] < nextDpVal[j])) {
                    nextDp[j] = dp[j];
                    nextDpVal[j] = arr1[i];
                }
            }

            int idx = bisectRight(arr2, uniqueSize, prev);
            if (idx < uniqueSize) {
                if (dp[j] + 1 < nextDp[j + 1] || (dp[j] + 1 == nextDp[j + 1] && arr2[idx] < nextDpVal[j + 1])) {
                    nextDp[j + 1] = dp[j] + 1;
                    nextDpVal[j + 1] = arr2[idx];
                }
            }
        }

        free(dp);
        free(dpVal);
        dp = nextDp;
        dpVal = nextDpVal;
    }

    int result = -1;
    for (int j = 0; j <= arr1Size; j++) {
        if (dp[j] != 1e9) {
            result = j;
            break;
        }
    }

    free(dp);
    free(dpVal);
    return result;
}