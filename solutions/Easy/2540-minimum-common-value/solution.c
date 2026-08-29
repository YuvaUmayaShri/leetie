// ──────────────────────────────────────────────────
// Problem  : 2540. Minimum Common Value
// Difficulty: Easy
// Tags     : Array, Hash Table, Two Pointers, Binary Search
// Link     : https://leetcode.com/problems/minimum-common-value/
// Runtime  : 0 ms (beats 100%)
// Memory   : 15048000 (beats 74%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0;
    
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            return nums1[i];
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    return -1;
}