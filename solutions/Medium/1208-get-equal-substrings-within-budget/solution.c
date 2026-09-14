// ──────────────────────────────────────────────────
// Problem  : 1208. Get Equal Substrings Within Budget
// Difficulty: Medium
// Tags     : String, Binary Search, Sliding Window, Prefix Sum
// Link     : https://leetcode.com/problems/get-equal-substrings-within-budget/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8596000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

int equalSubstring(char* s, char* t, int maxCost) {
    int n = strlen(s);
    int left = 0;
    int currentCost = 0;
    int maxLength = 0;

    for (int right = 0; right < n; right++) {
        currentCost += abs(s[right] - t[right]);

        while (currentCost > maxCost) {
            currentCost -= abs(s[left] - t[left]);
            left++;
        }

        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}