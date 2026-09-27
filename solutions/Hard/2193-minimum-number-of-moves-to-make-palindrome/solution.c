// ──────────────────────────────────────────────────
// Problem  : 2193. Minimum Number of Moves to Make Palindrome
// Difficulty: Hard
// Tags     : Two Pointers, String, Greedy, Binary Indexed Tree
// Link     : https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/
// Runtime  : 15 ms (beats 100%)
// Memory   : 9048000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <string.h>

int minMovesToMakePalindrome(char* s) {
    int len = strlen(s);
    int left = 0;
    int right = len - 1;
    int moves = 0;

    while (left < right) {
        int l = left;
        int r = right;

        while (s[l] != s[r]) {
            r--;
        }

        if (l == r) {
            char temp = s[r];
            s[r] = s[r + 1];
            s[r + 1] = temp;
            moves++;
            continue;
        } else {
            while (r < right) {
                char temp = s[r];
                s[r] = s[r + 1];
                s[r + 1] = temp;
                moves++;
                r++;
            }
        }

        left++;
        right--;
    }

    return moves;
}