// ──────────────────────────────────────────────────
// Problem  : 242. Valid Anagram
// Difficulty: Easy
// Tags     : Hash Table, String, Sorting
// Link     : https://leetcode.com/problems/valid-anagram/
// Runtime  : 4 ms (beats 84%)
// Memory   : 46332000 (beats 42%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length()){
            return false;
        }
       char[] sarr =s.toCharArray();
       char[] tarr = t.toCharArray();
       Arrays.sort(sarr);
       Arrays.sort(tarr);
       return Arrays.equals(sarr,tarr);
        
        
    }
}