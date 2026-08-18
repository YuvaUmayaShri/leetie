// ──────────────────────────────────────────────────
// Problem  : 5. Longest Palindromic Substring
// Difficulty: Medium
// Tags     : Two Pointers, String, Dynamic Programming, Manacher
// Link     : https://leetcode.com/problems/longest-palindromic-substring/
// Runtime  : 13 ms (beats 96%)
// Memory   : 43640000 (beats 59%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() < 1) return "";
        
        int start = 0;
        int maxl=1;
        
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandFromMid(s, i, i);
            int len2 = expandFromMid(s, i, i + 1);
            int curmax = Math.max(len1, len2);
            
            if (curmax > maxl) {
                maxl=curmax;
                start=i-(curmax-1)/2;
            }
        }
        
        return s.substring(start, start+maxl);
    }
    
    private int expandFromMid(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1;
    }
}