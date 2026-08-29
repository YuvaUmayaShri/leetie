// ──────────────────────────────────────────────────
// Problem  : 1871. Jump Game VII
// Difficulty: Medium
// Tags     : String, Dynamic Programming, Sliding Window, Prefix Sum
// Link     : https://leetcode.com/problems/jump-game-vii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 11460000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <string.h>

bool canReach(char* s, int minJump, int maxJump) {
    int n = strlen(s);
    if (s[n - 1] != '0') {
        return false;
    }

    bool dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0] = true;

    int reachable_count = 0;

    for (int i = 1; i < n; i++) {
        if (i >= minJump && dp[i - minJump]) {
            reachable_count++;
        }
        if (i > maxJump && dp[i - maxJump - 1]) {
            reachable_count--;
        }
        if (s[i] == '0' && reachable_count > 0) {
            dp[i] = true;
        }
    }

    return dp[n - 1];
}