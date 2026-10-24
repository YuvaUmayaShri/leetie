// ──────────────────────────────────────────────────
// Problem  : 318. Maximum Product of Word Lengths
// Difficulty: Medium
// Tags     : Array, String, Bit Manipulation
// Link     : https://leetcode.com/problems/maximum-product-of-word-lengths/
// Runtime  : 14 ms (beats 54%)
// Memory   : 13884000 (beats 98%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int maxProduct(char** words, int wordsSize) {
    int masks[wordsSize];
    int lens[wordsSize];
    
    for (int i = 0; i < wordsSize; i++) {
        masks[i] = 0;
        lens[i] = 0;
        for (int j = 0; words[i][j] != '\0'; j++) {
            masks[i] |= (1 << (words[i][j] - 'a'));
            lens[i]++;
        }
    }
    
    int maxProd = 0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if ((masks[i] & masks[j]) == 0) {
                int prod = lens[i] * lens[j];
                if (prod > maxProd) {
                    maxProd = prod;
                }
            }
        }
    }
    
    return maxProd;
}