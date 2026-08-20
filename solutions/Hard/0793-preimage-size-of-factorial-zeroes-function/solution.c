// ──────────────────────────────────────────────────
// Problem  : 793. Preimage Size of Factorial Zeroes Function
// Difficulty: Hard
// Tags     : Math, Binary Search
// Link     : https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8564000 (beats 20%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

long f(long k) {
    long count = 0;
    while (k > 0) {
        count += k / 5;
        k /= 5;
    }
    return count;
}

int preimageSizeFZF(int k) {
    long left = 0;
    long right = 5L * (k + 1);

    while (left <= right) {
        long mid = left + (right - left) / 2;
        long zeroes = f(mid);

        if (zeroes == k) {
            return 5;
        } else if (zeroes < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;
}