// ──────────────────────────────────────────────────
// Problem  : 1760. Minimum Limit of Balls in a Bag
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
// Runtime  : 32 ms (beats 19%)
// Memory   : 16820000 (beats 24%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int minimumSize(int* nums, int numsSize, int maxOperations) {
    int left = 1;
    int right = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > right) {
            right = nums[i];
        }
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long ops = 0;

        for (int i = 0; i < numsSize; i++) {
            ops += (nums[i] - 1) / mid;
        }

        if (ops <= maxOperations) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}