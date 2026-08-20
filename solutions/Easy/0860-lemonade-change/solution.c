// ──────────────────────────────────────────────────
// Problem  : 860. Lemonade Change
// Difficulty: Easy
// Tags     : Array, Greedy
// Link     : https://leetcode.com/problems/lemonade-change/
// Runtime  : 0 ms (beats 100%)
// Memory   : 15524000 (beats 1%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {
    int five = 0;
    int ten = 0;

    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            five++;
        } else if (bills[i] == 10) {
            if (five == 0) return false;
            five--;
            ten++;
        } else {
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }

    return true;
}