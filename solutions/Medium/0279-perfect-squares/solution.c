// ──────────────────────────────────────────────────
// Problem  : 279. Perfect Squares
// Difficulty: Medium
// Tags     : Math, Dynamic Programming, Breadth-First Search, Knapsack Problem, Complete Knapsack
// Link     : https://leetcode.com/problems/perfect-squares/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8572000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <math.h>

int numSquares(int n) {
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = i; 
        for (int j = 1; j * j <= i; j++) {
            int temp = dp[i - j * j] + 1;
            if (temp < dp[i]) {
                dp[i] = temp;
            }
        }
    }
    
    int result = dp[n];
    free(dp);
    return result;
}