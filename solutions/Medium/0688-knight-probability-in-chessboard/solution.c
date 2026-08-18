// ──────────────────────────────────────────────────
// Problem  : 688. Knight Probability in Chessboard
// Difficulty: Medium
// Tags     : Dynamic Programming
// Link     : https://leetcode.com/problems/knight-probability-in-chessboard/
// Runtime  : N/A (beats 0%)
// Memory   : N/A (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <string.h>
#include <stdlib.h>

int repeatedStringMatch(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);

    int count = 1;
    int cur_len = len_a;
    
    char* s = (char*)malloc(len_a * 2 + len_b + 1);
    strcpy(s, a);

    while (cur_len < len_b) {
        strcat(s, a);
        cur_len += len_a;
        count++;
    }

    if (strstr(s, b) != NULL) {
        free(s);
        return count;
    }

    strcat(s, a);
    if (strstr(s, b) != NULL) {
        free(s);
        return count + 1;
    }

    free(s);
    return -1;
}