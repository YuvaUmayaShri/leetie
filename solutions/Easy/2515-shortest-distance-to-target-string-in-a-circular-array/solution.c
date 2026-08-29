// ──────────────────────────────────────────────────
// Problem  : 2515. Shortest Distance to Target String in a Circular Array
// Difficulty: Easy
// Tags     : Array, String
// Link     : https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
// Runtime  : 0 ms (beats 100%)
// Memory   : 11872000 (beats 77%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <string.h>
#include <stdlib.h>
#include <math.h>

int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
    int min_dist = wordsSize;

    for (int i = 0; i < wordsSize; i++) {
        if (strcmp(words[i], target) == 0) {
            int abs_dist = abs(i - startIndex);
            int circular_dist = wordsSize - abs_dist;
            
            int dist = abs_dist < circular_dist ? abs_dist : circular_dist;
            if (dist < min_dist) {
                min_dist = dist;
            }
        }
    }

    return min_dist == wordsSize ? -1 : min_dist;
}