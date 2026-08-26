// ──────────────────────────────────────────────────
// Problem  : 537. Complex Number Multiplication
// Difficulty: Medium
// Tags     : Math, String, Simulation
// Link     : https://leetcode.com/problems/complex-number-multiplication/
// Runtime  : 4 ms (beats 21%)
// Memory   : 43264000 (beats 6%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public String complexNumberMultiply(String num1, String num2) {
        String[] parts1 = num1.split("\\+|i");
        String[] parts2 = num2.split("\\+|i");

        int a1 = Integer.parseInt(parts1[0]);
        int b1 = Integer.parseInt(parts1[1]);

        int a2 = Integer.parseInt(parts2[0]);
        int b2 = Integer.parseInt(parts2[1]);

        int real = a1 * a2 - b1 * b2;
        int imag = a1 * b2 + a2 * b1;

        return real + "+" + imag + "i";
    }
}