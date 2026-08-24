// ──────────────────────────────────────────────────
// Problem  : 566. Reshape the Matrix
// Difficulty: Easy
// Tags     : Array, Matrix, Simulation
// Link     : https://leetcode.com/problems/reshape-the-matrix/
// Runtime  : N/A (beats 0%)
// Memory   : N/A (beats 0%)
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