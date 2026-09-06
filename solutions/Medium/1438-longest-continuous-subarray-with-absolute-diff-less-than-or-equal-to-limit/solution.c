// ──────────────────────────────────────────────────
// Problem  : 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// Difficulty: Medium
// Tags     : Array, Queue, Sliding Window, Heap (Priority Queue), Ordered Set, Monotonic Queue
// Link     : https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8508000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int longestSubarray(int* nums, int numsSize, int limit) {
    int* maxDeque = (int*)malloc(numsSize * sizeof(int));
    int* minDeque = (int*)malloc(numsSize * sizeof(int));
    int maxHead = 0, maxTail = 0;
    int minHead = 0, minTail = 0;
    int left = 0, maxLength = 0;

    for (int right = 0; right < numsSize; right++) {
        while (maxTail > maxHead && nums[maxDeque[maxTail - 1]] <= nums[right]) {
            maxTail--;
        }
        maxDeque[maxTail++] = right;

        while (minTail > minHead && nums[minDeque[minTail - 1]] >= nums[right]) {
            minTail--;
        }
        minDeque[minTail++] = right;

        while (nums[maxDeque[maxHead]] - nums[minDeque[minHead]] > limit) {
            left++;
            if (maxDeque[maxHead] < left) {
                maxHead++;
            }
            if (minDeque[minHead] < left) {
                minHead++;
            }
        }

        int currentLen = right - left + 1;
        if (currentLen > maxLength) {
            maxLength = currentLen;
        }
    }

    free(maxDeque);
    free(minDeque);
    return maxLength;
}