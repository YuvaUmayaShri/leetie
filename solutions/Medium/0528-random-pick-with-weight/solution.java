// ──────────────────────────────────────────────────
// Problem  : 528. Random Pick with Weight
// Difficulty: Medium
// Tags     : Array, Math, Binary Search, Prefix Sum, Randomized
// Link     : https://leetcode.com/problems/random-pick-with-weight/
// Runtime  : 25 ms (beats 59%)
// Memory   : 51692000 (beats 80%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

import java.util.Random;

class Solution {
    private int[] prefixSums;
    private int totalSum;
    private Random random;

    public Solution(int[] w) {
        prefixSums = new int[w.length];
        int currentSum = 0;
        for (int i = 0; i < w.length; i++) {
            currentSum += w[i];
            prefixSums[i] = currentSum;
        }
        totalSum = currentSum;
        random = new Random();
    }
    
    public int pickIndex() {
        int target = random.nextInt(totalSum) + 1;
        
        int left = 0;
        int right = prefixSums.length - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefixSums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
}