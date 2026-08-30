// ──────────────────────────────────────────────────
// Problem  : 2091. Removing Minimum and Maximum From Array
// Difficulty: Medium
// Tags     : Array, Greedy
// Link     : https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
// Runtime  : 0 ms (beats 100%)
// Memory   : 16840000 (beats 52%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minimumDeletions(int* nums, int numsSize) {
    if (numsSize == 1) return 1;

    int minIdx = 0, maxIdx = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[minIdx]) minIdx = i;
        if (nums[i] > nums[maxIdx]) maxIdx = i;
    }

    int left = MIN(minIdx, maxIdx);
    int right = MAX(minIdx, maxIdx);

    int option1 = right + 1;
    int option2 = numsSize - left;
    int option3 = (left + 1) + (numsSize - right);

    return MIN(option1, MIN(option2, option3));
}