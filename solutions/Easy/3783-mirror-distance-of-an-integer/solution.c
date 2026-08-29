// ──────────────────────────────────────────────────
// Problem  : 3783. Mirror Distance of an Integer
// Difficulty: Easy
// Tags     : Math
// Link     : https://leetcode.com/problems/mirror-distance-of-an-integer/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9308000 (beats 4%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int mirrorDistance(int n) {
    long long rev = 0;
    int temp = n;
    
    while (temp > 0) {
        rev = rev * 10 + (temp % 10);
        temp /= 10;
    }
    
    return abs(n - (int)rev);
}
