// ──────────────────────────────────────────────────
// Problem  : 1053. Previous Permutation With One Swap
// Difficulty: Medium
// Tags     : Array, Greedy
// Link     : https://leetcode.com/problems/previous-permutation-with-one-swap/
// Runtime  : 0 ms (beats 100%)
// Memory   : 20048000 (beats 14%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int* prevPermOpt1(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    int i = arrSize - 2;

    while (i >= 0 && arr[i] <= arr[i + 1]) {
        i--;
    }

    if (i < 0) {
        return arr;
    }

    int j = arrSize - 1;
    while (arr[j] >= arr[i] || arr[j] == arr[j - 1]) {
        j--;
    }

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    return arr;
}