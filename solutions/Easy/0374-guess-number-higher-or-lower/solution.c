// ──────────────────────────────────────────────────
// Problem  : 374. Guess Number Higher or Lower
// Difficulty: Easy
// Tags     : Binary Search, Interactive
// Link     : https://leetcode.com/problems/guess-number-higher-or-lower/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8500000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int guess(int num);

int guessNumber(int n) {
    int low = 1;
    int high = n;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int res = guess(mid);
        
        if (res == 0) {
            return mid;
        } else if (res == -1) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return -1;
}