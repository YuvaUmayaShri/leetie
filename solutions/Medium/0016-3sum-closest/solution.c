// ──────────────────────────────────────────────────
// Problem  : 16. 3Sum Closest
// Difficulty: Medium
// Tags     : Array, Two Pointers, Sorting
// Link     : https://leetcode.com/problems/3sum-closest/
// Runtime  : 16 ms (beats 35%)
// Memory   : 9116000 (beats 18%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int closestSum = nums[0] + nums[1] + nums[2];
    
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];
            
            if (abs(target - currentSum) < abs(target - closestSum)) {
                closestSum = currentSum;
            }
            
            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                return currentSum;
            }
        }
    }
    
    return closestSum;
}