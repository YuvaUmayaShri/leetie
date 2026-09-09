// ──────────────────────────────────────────────────
// Problem  : 3871. Count Commas in Range II
// Difficulty: Medium
// Tags     : Math
// Link     : https://leetcode.com/problems/count-commas-in-range-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9424000 (beats 58%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

long long countCommas(long long n) {
    long long totalCommas = 0;
    long long base = 1000;
    
    while (n >= base) {
        totalCommas += (n - base + 1);
        if (base > LLONG_MAX / 1000) {
            break;
        }
        base *= 1000;
    }
    
    return totalCommas;
}