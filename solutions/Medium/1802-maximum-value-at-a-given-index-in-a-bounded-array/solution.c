// ──────────────────────────────────────────────────
// Problem  : 1802. Maximum Value at a Given Index in a Bounded Array
// Difficulty: Medium
// Tags     : Math, Binary Search, Greedy
// Link     : https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8704000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

long long getSum(long long count, long long val) {
    if (count <= 0) return 0;
    if (val >= count) {
        return count * (2 * val - count + 1) / 2;
    } else {
        return val * (val + 1) / 2 + (count - val);
    }
}

int maxValue(int n, int index, int maxSum) {
    int left = 1;
    int right = maxSum;
    int ans = 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        long long leftSum = getSum(index, mid - 1);
        long long rightSum = getSum(n - 1 - index, mid - 1);
        long long totalSum = mid + leftSum + rightSum;

        if (totalSum <= maxSum) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}