// ──────────────────────────────────────────────────
// Problem  : 2914. Minimum Number of Changes to Make Binary String Beautiful
// Difficulty: Medium
// Tags     : String
// Link     : https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/
// Runtime  : 10 ms (beats 5%)
// Memory   : 46208000 (beats 60%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int minChanges(String s) {
        return (int) IntStream.range(0, s.length() / 2).filter(i -> s.charAt(2 * i) != s.charAt(2 * i + 1)).count();
    }
}