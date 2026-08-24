// ──────────────────────────────────────────────────
// Problem  : 1550. Three Consecutive Odds
// Difficulty: Easy
// Tags     : Array
// Link     : https://leetcode.com/problems/three-consecutive-odds/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8744000 (beats 42%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool threeConsecutiveOdds(int* arr, int arrSize) {
    int count = 0;
    
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) {
            count++;
            if (count == 3) {
                return true;
            }
        } else {
            count = 0;
        }
    }
    
    return false;
}