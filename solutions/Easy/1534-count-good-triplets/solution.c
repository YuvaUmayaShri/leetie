// ──────────────────────────────────────────────────
// Problem  : 1534. Count Good Triplets
// Difficulty: Easy
// Tags     : Array, Enumeration
// Link     : https://leetcode.com/problems/count-good-triplets/
// Runtime  : 7 ms (beats 94%)
// Memory   : 8888000 (beats 62%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int count = 0;
    
    for (int i = 0; i < arrSize - 2; i++) {
        for (int j = i + 1; j < arrSize - 1; j++) {
            if (abs(arr[i] - arr[j]) > a) {
                continue;
            }
            
            for (int k = j + 1; k < arrSize; k++) {
                if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                    count++;
                }
            }
        }
    }
    
    return count;
}