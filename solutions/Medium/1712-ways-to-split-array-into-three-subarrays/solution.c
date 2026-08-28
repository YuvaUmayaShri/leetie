// ──────────────────────────────────────────────────
// Problem  : 1712. Ways to Split Array Into Three Subarrays
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search, Prefix Sum
// Link     : https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
// Runtime  : 38 ms (beats 67%)
// Memory   : 22916000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int binarySearchLeft(long long* prefix, int left, int right, long long target) {
    int res = right + 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (prefix[mid] >= target) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

int binarySearchRight(long long* prefix, int left, int right, long long target) {
    int res = left - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (prefix[mid] <= target) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}

int waysToSplit(int* nums, int numsSize) {
    int MOD = 1e9 + 7;
    long long* prefix = (long long*)malloc(numsSize * sizeof(long long));
    prefix[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        prefix[i] = prefix[i - 1] + nums[i];
    }

    long long count = 0;
    long long totalSum = prefix[numsSize - 1];

    for (int i = 0; i < numsSize - 2; i++) {
        long long leftSum = prefix[i];
        
        if (leftSum * 3 > totalSum) {
            break;
        }

        int minJ = binarySearchLeft(prefix, i + 1, numsSize - 2, 2 * leftSum);
        int maxJ = binarySearchRight(prefix, i + 1, numsSize - 2, leftSum + (totalSum - leftSum) / 2);

        if (minJ <= maxJ) {
            count = (count + (maxJ - minJ + 1)) % MOD;
        }
    }

    free(prefix);
    return count;
}