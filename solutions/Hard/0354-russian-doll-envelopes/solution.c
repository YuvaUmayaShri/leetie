// ──────────────────────────────────────────────────
// Problem  : 354. Russian Doll Envelopes
// Difficulty: Hard
// Tags     : Array, Binary Search, Dynamic Programming, Sorting, Longest Increasing Subsequence
// Link     : https://leetcode.com/problems/russian-doll-envelopes/
// Runtime  : 33 ms (beats 70%)
// Memory   : 32992000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    int compare(const void* a, const void* b) {
        int* env1 = *(int**)a;
        int* env2 = *(int**)b;
        if (env1[0] != env2[0]) {
            return env1[0] - env2[0];
        }
        return env2[1] - env1[1];
    }
    
    qsort(envelopes, envelopesSize, sizeof(int*), compare);
    
    int dp[envelopesSize];
    int len = 0;
    
    for (int i = 0; i < envelopesSize; i++) {
        int h = envelopes[i][1];
        int left = 0, right = len;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (dp[mid] < h) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        dp[left] = h;
        if (left == len) {
            len++;
        }
    }
    
    return len;
}