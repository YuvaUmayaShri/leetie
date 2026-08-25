// ──────────────────────────────────────────────────
// Problem  : 3002. Maximum Size of a Set After Removals
// Difficulty: Medium
// Tags     : Array, Hash Table, Greedy
// Link     : https://leetcode.com/problems/maximum-size-of-a-set-after-removals/
// Runtime  : 59 ms (beats 71%)
// Memory   : 17116000 (beats 86%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    long arg1 = *(const int*)a;
    long arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int removeDuplicates(int* arr, int n) {
    if (n == 0) return 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}

int maximumSetSize(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size;
    int target = n / 2;

    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int len1 = removeDuplicates(nums1, nums1Size);
    int len2 = removeDuplicates(nums2, nums2Size);

    int only1 = 0, only2 = 0, common = 0;

    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (nums1[i] < nums2[j]) {
            only1++;
            i++;
        } else if (nums1[i] > nums2[j]) {
            only2++;
            j++;
        } else {
            common++;
            i++;
            j++;
        }
    }

    only1 += (len1 - i);
    only2 += (len2 - j);

    int count1 = (only1 < target) ? only1 : target;
    int count2 = (only2 < target) ? only2 : target;

    int total = count1 + count2 + common;

    return (total < n) ? total : n;
}