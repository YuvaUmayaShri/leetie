// ──────────────────────────────────────────────────
// Problem  : 60. Permutation Sequence
// Difficulty: Hard
// Tags     : Math, Recursion
// Link     : https://leetcode.com/problems/permutation-sequence/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8492000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

char* getPermutation(int n, int k) {
    int fact[10];
    fact[0] = 1;
    for (int i = 1; i < 10; i++) {
        fact[i] = fact[i - 1] * i;
    }

    int nums[9];
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    char* result = (char*)malloc((n + 1) * sizeof(char));
    result[n] = '\0';

    k--;

    for (int i = 0; i < n; i++) {
        int index = k / fact[n - 1 - i];
        result[i] = nums[index] + '0';

        for (int j = index; j < n - 1 - i; j++) {
            nums[j] = nums[j + 1];
        }

        k %= fact[n - 1 - i];
    }

    return result;
}