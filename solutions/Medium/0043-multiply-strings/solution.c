// ──────────────────────────────────────────────────
// Problem  : 43. Multiply Strings
// Difficulty: Medium
// Tags     : Math, String, Simulation
// Link     : https://leetcode.com/problems/multiply-strings/
// Runtime  : 1 ms (beats 62%)
// Memory   : 8916000 (beats 56%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        strcpy(result, "0");
        return result;
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int totalLen = len1 + len2;

    int* res = (int*)calloc(totalLen, sizeof(int));

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + res[i + j + 1];

            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }

    int start = 0;
    while (start < totalLen && res[start] == 0) {
        start++;
    }

    char* result = (char*)malloc((totalLen - start + 1) * sizeof(char));
    int idx = 0;

    for (int i = start; i < totalLen; i++) {
        result[idx++] = res[i] + '0';
    }
    result[idx] = '\0';

    free(res);
    return result;
}