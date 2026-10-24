// ──────────────────────────────────────────────────
// Problem  : 330. Patching Array
// Difficulty: Hard
// Tags     : Array, Greedy
// Link     : https://leetcode.com/problems/patching-array/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8600000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int minPatches(int* nums, int numsSize, int n) {
    long long miss = 1;
    int patches = 0;
    int i = 0;
    
    while (miss <= n) {
        if (i < numsSize && nums[i] <= miss) {
            miss += nums[i];
            i++;
        } else {
            miss += miss;
            patches++;
        }
    }
    
    return patches;
}