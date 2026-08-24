// ──────────────────────────────────────────────────
// Problem  : 798. Smallest Rotation with Highest Score
// Difficulty: Hard
// Tags     : Array, Prefix Sum
// Link     : https://leetcode.com/problems/smallest-rotation-with-highest-score/
// Runtime  : 7 ms (beats 40%)
// Memory   : 18736000 (beats 10%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int bestRotation(int* nums, int numsSize) {
    int* diff = (int*)calloc(numsSize + 1, sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        int low = (i + 1) % numsSize;
        int high = (i - nums[i] + numsSize + 1) % numsSize;
        
        diff[low]++;
        diff[high]--;
        
        if (low >= high) {
            diff[0]++;
        }
    }
    
    int maxScore = -1;
    int bestK = 0;
    int currentScore = 0;
    
    for (int k = 0; k < numsSize; k++) {
        currentScore += diff[k];
        if (currentScore > maxScore) {
            maxScore = currentScore;
            bestK = k;
        }
    }
    
    free(diff);
    return bestK;
}