// ──────────────────────────────────────────────────
// Problem  : 744. Find Smallest Letter Greater Than Target
// Difficulty: Easy
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9036000 (beats 83%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int low = 0;
    int high = lettersSize - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (letters[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return letters[low % lettersSize];
}