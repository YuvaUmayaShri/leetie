// ──────────────────────────────────────────────────
// Problem  : 878. Nth Magical Number
// Difficulty: Hard
// Tags     : Math, Binary Search, Least Common Multiple, Inclusion-Exclusion Principle
// Link     : https://leetcode.com/problems/nth-magical-number/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8616000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

long long gcd(long long x, long long y) {
    while (y > 0) {
        long long temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int nthMagicalNumber(int n, int a, int b) {
    long long MOD = 1000000007;
    long long L = lcm(a, b);
    
    long long low = 1;
    long long high = (long long)n * (a < b ? a : b);
    long long ans = high;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long count = (mid / a) + (mid / b) - (mid / L);
        
        if (count >= n) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return (int)(ans % MOD);
}