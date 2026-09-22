// ──────────────────────────────────────────────────
// Problem  : 698. Partition to K Equal Sum Subsets
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Backtracking, Bit Manipulation, Memoization, Bitmask
// Link     : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// Runtime  : 1 ms (beats 47%)
// Memory   : 8656000 (beats 80%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int compareDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

static bool backtrack(int* nums, int numsSize, int* visited, int start_idx, int k, int current_sum, int target) {
    if (k == 1) {
        return true;
    }
    if (current_sum == target) {
        return backtrack(nums, numsSize, visited, 0, k - 1, 0, target);
    }

    for (int i = start_idx; i < numsSize; i++) {
        if (visited[i] || current_sum + nums[i] > target) {
            continue;
        }

        visited[i] = 1;
        if (backtrack(nums, numsSize, visited, i + 1, k, current_sum + nums[i], target)) {
            return true;
        }
        visited[i] = 0;

        while (i + 1 < numsSize && nums[i] == nums[i + 1]) {
            i++;
        }
    }

    return false;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    if (sum % k != 0) {
        return false;
    }

    int target = sum / k;

    qsort(nums, numsSize, sizeof(int), compareDesc);

    if (nums[0] > target) {
        return false;
    }

    int* visited = (int*)calloc(numsSize, sizeof(int));
    bool result = backtrack(nums, numsSize, visited, 0, k, 0, target);

    free(visited);
    return result;
}