// ──────────────────────────────────────────────────
// Problem  : 3863. Minimum Operations to Sort a String
// Difficulty: Medium
// Tags     : String
// Link     : https://leetcode.com/problems/minimum-operations-to-sort-a-string/
// Runtime  : 7 ms (beats 88%)
// Memory   : 13708000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int minOperations(char* s) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    
    int sorted = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i+1]) {
            sorted = 0;
            break;
        }
    }
    if (sorted) return 0;
    
    if (n <= 2) return -1;
    
    char mn = s[0], mx = s[0];
    for (int i = 0; i < n; i++) {
        if (s[i] < mn) mn = s[i];
        if (s[i] > mx) mx = s[i];
    }
    
    if (s[0] == mn || s[n-1] == mx) return 1;
    
    int first_is_mx = (s[0] == mx);
    for (int i = 1; i < n; i++) {
        if (s[i] == mx) {
            first_is_mx = 0;
            break;
        }
    }
    
    int last_is_mn = (s[n-1] == mn);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == mn) {
            last_is_mn = 0;
            break;
        }
    }
    
    if (first_is_mx && last_is_mn) return 3;
    
    return 2;
}