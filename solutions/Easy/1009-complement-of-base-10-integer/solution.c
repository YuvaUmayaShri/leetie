// ──────────────────────────────────────────────────
// Problem  : 1009. Complement of Base 10 Integer
// Difficulty: Easy
// Tags     : Bit Manipulation
// Link     : https://leetcode.com/problems/complement-of-base-10-integer/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8436000 (beats 92%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int bitwiseComplement(int n) {
    if (n == 0) return 1;

    unsigned int mask = ~0;
    while (n & mask) {
        mask <<= 1;
    }

    return ~n & ~mask;
}