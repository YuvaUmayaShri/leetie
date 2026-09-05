// ──────────────────────────────────────────────────
// Problem  : 680. Valid Palindrome II
// Difficulty: Easy
// Tags     : Two Pointers, String, Greedy
// Link     : https://leetcode.com/problems/valid-palindrome-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12080000 (beats 67%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>

bool isPalindromeRange(char* s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return isPalindromeRange(s, left + 1, right) || isPalindromeRange(s, left, right - 1);
        }
        left++;
        right--;
    }

    return true;
}