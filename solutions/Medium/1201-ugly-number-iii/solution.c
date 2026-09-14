// ──────────────────────────────────────────────────
// Problem  : 1201. Ugly Number III
// Difficulty: Medium
// Tags     : Math, Binary Search, Combinatorics, Number Theory, Least Common Multiple, Euclidean Algorithm, Greatest Common Divisor, Inclusion-Exclusion Principle
// Link     : https://leetcode.com/problems/ugly-number-iii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8592000 (beats 33%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdint.h>

long long gcd(long long a, long long b) {
    while (b) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int nthUglyNumber(int n, int a, int b, int c) {
    long long A = a, B = b, C = c;
    long long ab = lcm(A, B);
    long long ac = lcm(A, C);
    long long bc = lcm(B, C);
    long long abc = lcm(A, bc);

    long long low = 1, high = 2e9;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long count = mid / A + mid / B + mid / C 
                        - mid / ab - mid / ac - mid / bc 
                        + mid / abc;

        if (count >= n) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return (int)ans;
}