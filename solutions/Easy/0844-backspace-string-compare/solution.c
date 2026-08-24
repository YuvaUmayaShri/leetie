// ──────────────────────────────────────────────────
// Problem  : 844. Backspace String Compare
// Difficulty: Easy
// Tags     : Two Pointers, String, Stack, Simulation
// Link     : https://leetcode.com/problems/backspace-string-compare/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8524000 (beats 82%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool backspaceCompare(char* s, char* t) {
    int i = strlen(s) - 1;
    int j = strlen(t) - 1;
    int skipS = 0, skipT = 0;

    while (i >= 0 || j >= 0) {
        while (i >= 0) {
            if (s[i] == '#') {
                skipS++;
                i--;
            } else if (skipS > 0) {
                skipS--;
                i--;
            } else {
                break;
            }
        }

        while (j >= 0) {
            if (t[j] == '#') {
                skipT++;
                j--;
            } else if (skipT > 0) {
                skipT--;
                j--;
            } else {
                break;
            }
        }

        if (i >= 0 && j >= 0 && s[i] != t[j]) {
            return false;
        }

        if ((i >= 0) != (j >= 0)) {
            return false;
        }

        i--;
        j--;
    }

    return true;
}