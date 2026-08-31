// ──────────────────────────────────────────────────
// Problem  : 1611. Minimum One Bit Operations to Make Integers Zero
// Difficulty: Hard
// Tags     : Math, Dynamic Programming, Bit Manipulation, Recursion, Memoization
// Link     : https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8520000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int minimumOneBitOperations(int n) {
    int ans = 0;
    while (n > 0) {
        ans ^= n;
        n >>= 1;
    }
    return ans;
}