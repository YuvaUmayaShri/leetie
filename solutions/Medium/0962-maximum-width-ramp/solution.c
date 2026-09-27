// ──────────────────────────────────────────────────
// Problem  : 962. Maximum Width Ramp
// Difficulty: Medium
// Tags     : Array, Two Pointers, Stack, Monotonic Stack
// Link     : https://leetcode.com/problems/maximum-width-ramp/
// Runtime  : 5 ms (beats 33%)
// Memory   : 13488000 (beats 56%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int maxWidthRamp(int* nums, int numsSize) {
    int* stack = (int*)malloc(numsSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < numsSize; i++) {
        if (top == -1 || nums[stack[top]] > nums[i]) {
            stack[++top] = i;
        }
    }

    int maxWidth = 0;

    for (int j = numsSize - 1; j >= 0; j--) {
        while (top >= 0 && nums[stack[top]] <= nums[j]) {
            int width = j - stack[top];
            if (width > maxWidth) {
                maxWidth = width;
            }
            top--;
        }
    }

    free(stack);
    return maxWidth;
}