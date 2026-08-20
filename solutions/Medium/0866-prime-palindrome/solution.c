// ──────────────────────────────────────────────────
// Problem  : 866. Prime Palindrome
// Difficulty: Medium
// Tags     : Math, Number Theory, Primality Test
// Link     : https://leetcode.com/problems/prime-palindrome/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8484000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <math.h>

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int reverseNumber(int num) {
    int rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

int primePalindrome(int n) {
    if (8 <= n && n <= 11) {
        return 11;
    }

    for (int i = 1; i < 100000; i++) {
        int rev = reverseNumber(i / 10);
        int pal = i;
        int temp = rev;
        
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