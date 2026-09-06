// ──────────────────────────────────────────────────
// Problem  : 115. Distinct Subsequences
// Difficulty: Hard
// Tags     : String, Dynamic Programming
// Link     : https://leetcode.com/problems/distinct-subsequences/
// Runtime  : 8 ms (beats 91%)
// Memory   : 9040000 (beats 86%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};