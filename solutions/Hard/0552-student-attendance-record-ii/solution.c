// ──────────────────────────────────────────────────
// Problem  : 552. Student Attendance Record II
// Difficulty: Hard
// Tags     : Dynamic Programming
// Link     : https://leetcode.com/problems/student-attendance-record-ii/
// Runtime  : 2 ms (beats 0%)
// Memory   : 8412000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int checkRecord(int n) {
    long long dp[2][3] = {0};
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        long long next_dp[2][3] = {0};

        for (int a = 0; a < 2; a++) {
            for (int l = 0; l < 3; l++) {
                if (dp[a][l] == 0) continue;

                next_dp[a][0] = (next_dp[a][0] + dp[a][l]) % MOD;

                if (a < 1) {
                    next_dp[a + 1][0] = (next_dp[a + 1][0] + dp[a][l]) % MOD;
                }

                if (l < 2) {
                    next_dp[a][l + 1] = (next_dp[a][l + 1] + dp[a][l]) % MOD;
                }
            }
        }

        for (int a = 0; a < 2; a++) {
            for (int l = 0; l < 3; l++) {
                dp[a][l] = next_dp[a][l];
            }
        }
    }

    long long ans = 0;
    for (int a = 0; a < 2; a++) {
        for (int l = 0; l < 3; l++) {
            ans = (ans + dp[a][l]) % MOD;
        }
    }

    return (int)ans;
}