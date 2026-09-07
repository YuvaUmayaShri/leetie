// ──────────────────────────────────────────────────
// Problem  : 940. Distinct Subsequences II
// Difficulty: Hard
// Tags     : String, Dynamic Programming
// Link     : https://leetcode.com/problems/distinct-subsequences-ii/
// Runtime  : 5 ms (beats 0%)
// Memory   : 8876000 (beats 67%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int distinctSubseqII(char* s) {
    long last[26] = {0};
    long mod = 1e9 + 7;
    
    for (int i = 0; s[i] != '\0'; i++) {
        int char_idx = s[i] - 'a';
        long current_total = 1;
        
        for (int j = 0; j < 26; j++) {
            current_total = (current_total + last[j]) % mod;
        }
        
        last[char_idx] = current_total;
    }
    
    long ans = 0;
    for (int i = 0; i < 26; i++) {
        ans = (ans + last[i]) % mod;
    }
    
    return ans;
}