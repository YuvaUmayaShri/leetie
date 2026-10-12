// ──────────────────────────────────────────────────
// Problem  : 2897. Apply Operations on Array to Maximize Sum of Squares
// Difficulty: Hard
// Tags     : Array, Hash Table, Greedy, Bit Manipulation
// Link     : https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/
// Runtime  : 89 ms (beats 75%)
// Memory   : 18100000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int maxSum(int* nums, int numsSize, int k) {
    int bit_counts[31] = {0};
    for (int i = 0; i < numsSize; i++) {
        for (int b = 0; b <= 30; b++) {
            if ((nums[i] >> b) & 1) {
                bit_counts[b]++;
            }
        }
    }
    
    long long total_sum = 0;
    long long MOD = 1000000007;
    
    for (int i = 0; i < k; i++) {
        long long current_val = 0;
        for (int b = 30; b >= 0; b--) {
            if (bit_counts[b] > 0) {
                current_val |= (1LL << b);
                bit_counts[b]--;
            }
        }
        total_sum = (total_sum + (current_val * current_val) % MOD) % MOD;
    }
    
    return (int)total_sum;
}