// ──────────────────────────────────────────────────
// Problem  : 3507. Minimum Pair Removal to Sort Array I
// Difficulty: Easy
// Tags     : Array, Hash Table, Linked List, Heap (Priority Queue), Simulation, Doubly-Linked List, Ordered Set
// Link     : https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8468000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool isNonDecreasing(int* nums, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return false;
        }
    }
    return true;
}

int minimumPairRemoval(int* nums, int numsSize) {
    int ops = 0;
    while (!isNonDecreasing(nums, numsSize)) {
        int minIdx = 0;
        int minSum = nums[0] + nums[1];

        for (int i = 1; i < numsSize - 1; i++) {
            int sum = nums[i] + nums[i + 1];
            if (sum < minSum) {
                minSum = sum;
                minIdx = i;
            }
        }

        nums[minIdx] = minSum;
        for (int i = minIdx + 1; i < numsSize - 1; i++) {
            nums[i] = nums[i + 1];
        }

        numsSize--;
        ops++;
    }
    return ops;
}