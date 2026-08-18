// ──────────────────────────────────────────────────
// Problem  : 689. Maximum Sum of 3 Non-Overlapping Subarrays
// Difficulty: Hard
// Tags     : Array, Dynamic Programming, Sliding Window, Prefix Sum
// Link     : https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8500000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = 3;
    int* result = (int*)malloc(3 * sizeof(int));
    
    int n = numsSize;
    int W_size = n - k + 1;
    int* W = (int*)malloc(W_size * sizeof(int));
    
    int curr_sum = 0;
    for (int i = 0; i < k; i++) {
        curr_sum += nums[i];
    }
    W[0] = curr_sum;
    
    for (int i = 1; i < W_size; i++) {
        curr_sum += nums[i + k - 1] - nums[i - 1];
        W[i] = curr_sum;
    }
    
    int* left = (int*)malloc(W_size * sizeof(int));
    int best_left = 0;
    for (int i = 0; i < W_size; i++) {
        if (W[i] > W[best_left]) {
            best_left = i;
        }
        left[i] = best_left;
    }
    
    int* right = (int*)malloc(W_size * sizeof(int));
    int best_right = W_size - 1;
    for (int i = W_size - 1; i >= 0; i--) {
        if (W[i] >= W[best_right]) {
            best_right = i;
        }
        right[i] = best_right;
    }
    
    int max_total = -1;
    for (int j = k; j < W_size - k; j++) {
        int l = left[j - k];
        int r = right[j + k];
        int total = W[l] + W[j] + W[r];
        if (total > max_total) {
            max_total = total;
            result[0] = l;
            result[1] = j;
            result[2] = r;
        }
    }
    
    free(W);
    free(left);
    free(right);
    
    return result;
}