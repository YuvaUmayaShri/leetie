// ──────────────────────────────────────────────────
// Problem  : 1332. Remove Palindromic Subsequences
// Difficulty: Easy
// Tags     : Two Pointers, String
// Link     : https://leetcode.com/problems/remove-palindromic-subsequences/
// Runtime  : 0 ms (beats 100%)
// Memory   : 42544000 (beats 81%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int removePalindromeSub(String s) {
        if (s.isEmpty()) return 0;
        
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return 2;
            }
            left++;
            right--;
        }
        
        return 1;
    }
}