// ──────────────────────────────────────────────────
// Problem  : 3876. Construct Uniform Parity Array II
// Difficulty: Medium
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/construct-uniform-parity-array-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 20336000 (beats 60%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <limits.h>

bool uniformArray(int* nums1, int nums1Size) {
    int min_odd = INT_MAX;
    int min_even = INT_MAX;

    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] % 2 != 0) {
            if (nums1[i] < min_odd) {
                min_odd = nums1[i];
            }
        } else {
            if (nums1[i] < min_even) {
                min_even = nums1[i];
            }
        }
    }

    if (min_odd == INT_MAX || min_even == INT_MAX) {
        return true;
    }

    return min_odd < min_even;
}