// ──────────────────────────────────────────────────
// Problem  : 796. Rotate String
// Difficulty: Easy
// Tags     : String, String Matching
// Link     : https://leetcode.com/problems/rotate-string/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8520000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool rotateString(char* s, char* goal) {
    int lenS = strlen(s);
    int lenGoal = strlen(goal);

    if (lenS != lenGoal) {
        return false;
    }

    char doubleS[201];
    strcpy(doubleS, s);
    strcat(doubleS, s);

    return strstr(doubleS, goal) != NULL;
}