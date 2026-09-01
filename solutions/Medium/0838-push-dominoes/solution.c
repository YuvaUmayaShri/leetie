// ──────────────────────────────────────────────────
// Problem  : 838. Push Dominoes
// Difficulty: Medium
// Tags     : Two Pointers, String, Dynamic Programming
// Link     : https://leetcode.com/problems/push-dominoes/
// Runtime  : 15 ms (beats 30%)
// Memory   : 17376000 (beats 20%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* pushDominoes(char* dominoes) {
    int n = strlen(dominoes);
    int* forces = (int*)calloc(n, sizeof(int));

    int force = 0;
    for (int i = 0; i < n; i++) {
        if (dominoes[i] == 'R') {
            force = n;
        } else if (dominoes[i] == 'L') {
            force = 0;
        } else {
            force = force > 0 ? force - 1 : 0;
        }
        forces[i] += force;
    }

    force = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (dominoes[i] == 'L') {
            force = n;
        } else if (dominoes[i] == 'R') {
            force = 0;
        } else {
            force = force > 0 ? force - 1 : 0;
        }
        forces[i] -= force;
    }

    char* result = (char*)malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        if (forces[i] > 0) {
            result[i] = 'R';
        } else if (forces[i] < 0) {
            result[i] = 'L';
        } else {
            result[i] = '.';
        }
    }
    result[n] = '\0';

    free(forces);
    return result;
}