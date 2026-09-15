// ──────────────────────────────────────────────────
// Problem  : 2472. Maximum Number of Non-overlapping Palindrome Substrings
// Difficulty: Hard
// Tags     : Two Pointers, String, Dynamic Programming, Greedy
// Link     : https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8852000 (beats 74%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <string.h>

bool isPalindrome(const char* s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int maxPalindromes(char* s, int k) {
    int n = strlen(s);
    int count = 0;
    int i = 0;

    while (i <= n - k) {
        if (isPalindrome(s, i, i + k - 1)) {
            count++;
            i = i + k;
        } else if (i + k < n && isPalindrome(s, i, i + k)) {
            count++;
            i = i + k + 1;
        } else {
            i++;
        }
    }

    return count;
}