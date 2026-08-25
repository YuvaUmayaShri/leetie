// ──────────────────────────────────────────────────
// Problem  : 3079. Find the Sum of Encrypted Integers
// Difficulty: Easy
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/find-the-sum-of-encrypted-integers/
// Runtime  : 5 ms (beats 0%)
// Memory   : 8324000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int encrypt(int x) {
    int max_digit = 0;
    int base = 0;
    while (x > 0) {
        int digit = x % 10;
        if (digit > max_digit) {
            max_digit = digit;
        }
        base = base * 10 + 1;
        x /= 10;
    }
    return max_digit * base;
}

int sumOfEncryptedInt(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += encrypt(nums[i]);
    }
    return sum;
}