// ──────────────────────────────────────────────────
// Problem  : 859. Buddy Strings
// Difficulty: Easy
// Tags     : Hash Table, String
// Link     : https://leetcode.com/problems/buddy-strings/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8872000 (beats 26%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <string.h>

bool buddyStrings(char* s, char* goal) {
    int lenS = strlen(s);
    int lenGoal = strlen(goal);

    if (lenS != lenGoal) {
        return false;
    }

    if (strcmp(s, goal) == 0) {
        int count[26] = {0};
        for (int i = 0; i < lenS; i++) {
            count[s[i] - 'a']++;
            if (count[s[i] - 'a'] > 1) {
                return true;
            }
        }
        return false;
    }

    int first = -1, second = -1;
    for (int i = 0; i < lenS; i++) {
        if (s[i] != goal[i]) {
            if (first == -1) {
                first = i;
            } else if (second == -1) {
                second = i;
            } else {
                return false;
            }
        }
    }

    return (second != -1 && s[first] == goal[second] && s[second] == goal[first]);
}