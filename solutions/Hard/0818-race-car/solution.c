// ──────────────────────────────────────────────────
// Problem  : 818. Race Car
// Difficulty: Hard
// Tags     : Dynamic Programming, Heuristic Search, A* Search
// Link     : https://leetcode.com/problems/race-car/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8744000 (beats 80%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int racecar(int target) {
    static int dp[10001] = {0};
    if (dp[target] > 0) return dp[target];

    // Find smallest n such that (2^n - 1) >= target
    int n = (int)ceil(log2(target + 1));
    if ((1 << n) - 1 == target) {
        return dp[target] = n;
    }

    // Option 1: Pass target, reverse, and come back
    // Instructions: n 'A's + 1 'R'
    dp[target] = n + 1 + racecar((1 << n) - 1 - target);

    // Option 2: Stop before target (n - 1 steps), reverse, drive back m steps, reverse again, and proceed
    // Instructions: (n - 1) 'A's + 1 'R' + m 'A's + 1 'R'
    for (int m = 0; m < n - 1; m++) {
        int back_dist = (1 << (n - 1)) - 1 - ((1 << m) - 1);
        int steps = (n - 1) + 1 + m + 1 + racecar(target - back_dist);
        if (steps < dp[target]) {
            dp[target] = steps;
        }
    }

    return dp[target];
}