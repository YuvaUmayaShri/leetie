// ──────────────────────────────────────────────────
// Problem  : 441. Arranging Coins
// Difficulty: Easy
// Tags     : Math, Binary Search
// Link     : https://leetcode.com/problems/arranging-coins/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9228000 (beats 77%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int arrangeCoins(int n) {
    long low = 0;
    long high = n;
    
    while (low <= high) {
        long mid = low + (high - low) / 2;
        long coinsUsed = mid * (mid + 1) / 2;
        
        if (coinsUsed == n) {
            return (int)mid;
        } else if (coinsUsed < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return (int)high;
}