// ──────────────────────────────────────────────────
// Problem  : 164. Maximum Gap
// Difficulty: Medium
// Tags     : Array, Sorting, Bucket Sort, Radix Sort, Pigeonhole Principle
// Link     : https://leetcode.com/problems/maximum-gap/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8548000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) {
        return 0;
    }

    int minVal = nums[0];
    int maxVal = nums[0];

    for (int i = 1; i < numsSize; i++) {
        minVal = MIN(minVal, nums[i]);
        maxVal = MAX(maxVal, nums[i]);
    }

    if (minVal == maxVal) {
        return 0;
    }

    int bucketSize = MAX(1, (maxVal - minVal) / (numsSize - 1));
    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    int* minBucket = (int*)malloc(bucketCount * sizeof(int));
    int* maxBucket = (int*)malloc(bucketCount * sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        minBucket[i] = INT_MAX;
        maxBucket[i] = INT_MIN;
    }

    for (int i = 0; i < numsSize; i++) {
        int idx = (nums[i] - minVal) / bucketSize;
        minBucket[idx] = MIN(minBucket[idx], nums[i]);
        maxBucket[idx] = MAX(maxBucket[idx], nums[i]);
    }

    int maxGap = 0;
    int prevMax = minVal;

    for (int i = 0; i < bucketCount; i++) {
        if (minBucket[i] == INT_MAX) {
            continue;
        }
        maxGap = MAX(maxGap, minBucket[i] - prevMax);
        prevMax = maxBucket[i];
    }

    free(minBucket);
    free(maxBucket);

    return maxGap;
}