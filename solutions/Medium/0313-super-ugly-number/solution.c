// ──────────────────────────────────────────────────
// Problem  : 313. Super Ugly Number
// Difficulty: Medium
// Tags     : Array, Math, Dynamic Programming
// Link     : https://leetcode.com/problems/super-ugly-number/
// Runtime  : 44 ms (beats 68%)
// Memory   : 10048000 (beats 75%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int* ugly = (int*)malloc(n * sizeof(int));
    ugly[0] = 1;

    int* idx = (int*)calloc(primesSize, sizeof(int));
    int* next = (int*)malloc(primesSize * sizeof(int));

    for (int i = 0; i < primesSize; i++) {
        next[i] = primes[i];
    }

    for (int i = 1; i < n; i++) {
        int minVal = next[0];
        for (int j = 1; j < primesSize; j++) {
            if (next[j] < minVal) {
                minVal = next[j];
            }
        }
        ugly[i] = minVal;

        for (int j = 0; j < primesSize; j++) {
            if (next[j] == minVal) {
                idx[j]++;
                long long prod = (long long)ugly[idx[j]] * primes[j];
                next[j] = (prod > 2147483647LL) ? 2147483647 : (int)prod;
            }
        }
    }

    int result = ugly[n - 1];
    free(ugly);
    free(idx);
    free(next);
    return result;
}