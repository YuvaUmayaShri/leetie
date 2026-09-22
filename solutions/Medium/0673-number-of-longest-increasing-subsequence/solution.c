// ──────────────────────────────────────────────────
// Problem  : 673. Number of Longest Increasing Subsequence
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Binary Indexed Tree, Segment Tree, Longest Increasing Subsequence
// Link     : https://leetcode.com/problems/number-of-longest-increasing-subsequence/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8784000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int findNumberOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int* lengths = (int*)malloc(numsSize * sizeof(int));
    int* counts = (int*)malloc(numsSize * sizeof(int));

    int max_len = 0;
    int result = 0;

    for (int i = 0; i < numsSize; i++) {
        lengths[i] = 1;
        counts[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (lengths[j] + 1 > lengths[i]) {
                    lengths[i] = lengths[j] + 1;
                    counts[i] = counts[j];
                } else if (lengths[j] + 1 == lengths[i]) {
                    counts[i] += counts[j];
                }
            }
        }
        if (lengths[i] > max_len) {
            max_len = lengths[i];
            result = counts[i];
        } else if (lengths[i] == max_len) {
            result += counts[i];
        }
    }

    free(lengths);
    free(counts);

    return result;
}