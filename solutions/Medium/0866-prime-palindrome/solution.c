// ──────────────────────────────────────────────────
// Problem  : 866. Prime Palindrome
// Difficulty: Medium
// Tags     : Math, Number Theory, Primality Test
// Link     : https://leetcode.com/problems/prime-palindrome/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8416000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int primePalindrome(int n) {
    if (8 <= n && n <= 11) {
        return 11;
    }

    // Generate odd-length palindromes from root 1 to 99999
    // Root 1 -> 1, Root 10 -> 101, Root 100 -> 10001, etc.
    for (int i = 1; i < 100000; i++) {
        int pal = i;
        int temp = i / 10;

        while (temp > 0) {
            pal = pal * 10 + temp % 10;
            temp /= 10;
        }

        if (pal >= n && isPrime(pal)) {
            return pal;
        }
    }

    return -1;
}