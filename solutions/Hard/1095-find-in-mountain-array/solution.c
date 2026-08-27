// ──────────────────────────────────────────────────
// Problem  : 1095. Find in Mountain Array
// Difficulty: Hard
// Tags     : Array, Binary Search, Interactive, Ternary Search
// Link     : https://leetcode.com/problems/find-in-mountain-array/
// Runtime  : 2 ms (beats 93%)
// Memory   : 9316000 (beats 36%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int binarySearchAscending(int target, MountainArray* mountainArr, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int val = get(mountainArr, mid);
        if (val == target) return mid;
        if (val < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarySearchDescending(int target, MountainArray* mountainArr, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int val = get(mountainArr, mid);
        if (val == target) return mid;
        if (val > target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int findInMountainArray(int target, MountainArray* mountainArr) {
    int len = length(mountainArr);
    
    int low = 1, high = len - 2;
    int peak = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int mid_val = get(mountainArr, mid);
        int next_val = get(mountainArr, mid + 1);
        if (mid_val < next_val) {
            low = mid + 1;
        } else {
            peak = mid;
            high = mid - 1;
        }
    }
    
    int index = binarySearchAscending(target, mountainArr, 0, peak);
    if (index != -1) return index;
    
    return binarySearchDescending(target, mountainArr, peak + 1, len - 1);
}