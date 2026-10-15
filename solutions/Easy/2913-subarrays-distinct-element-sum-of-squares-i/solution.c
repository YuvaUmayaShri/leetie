// ──────────────────────────────────────────────────
// Problem  : 2913. Subarrays Distinct Element Sum of Squares I
// Difficulty: Easy
// Tags     : Array, Hash Table, Binary Indexed Tree, Segment Tree
// Link     : https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/
// Runtime  : 30 ms (beats 13%)
// Memory   : 9680000 (beats 94%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int sumCounts(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j < numsSize; j++) {
            int count = 0;
            int seen[101] = {0};
            for (int k = i; k <= j; k++) {
                if (!seen[nums[k]]) {
                    seen[nums[k]] = 1;
                    count++;
                }
            }
            total += count * count;
        }
    }
    return total;
}