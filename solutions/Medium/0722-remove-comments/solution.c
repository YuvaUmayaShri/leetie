// ──────────────────────────────────────────────────
// Problem  : 722. Remove Comments
// Difficulty: Medium
// Tags     : Array, String
// Link     : https://leetcode.com/problems/remove-comments/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8696000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** removeComments(char** source, int sourceSize, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * sourceSize);
    *returnSize = 0;
    
    bool inBlock = false;
    char lineBuffer[10000];
    int bufIdx = 0;

    for (int i = 0; i < sourceSize; i++) {
        char* line = source[i];
        int len = strlen(line);
        int j = 0;

        while (j < len) {
            if (!inBlock && j + 1 < len && line[j] == '/' && line[j + 1] == '*') {
                inBlock = true;
                j += 2;
            } else if (inBlock && j + 1 < len && line[j] == '*' && line[j + 1] == '/') {
                inBlock = false;
                j += 2;
            } else if (!inBlock && j + 1 < len && line[j] == '/' && line[j + 1] == '/') {
                break;
            } else if (!inBlock) {
                lineBuffer[bufIdx++] = line[j++];
            } else {
                j++;
            }
        }

        if (!inBlock && bufIdx > 0) {
            lineBuffer[bufIdx] = '\0';
            result[*returnSize] = (char*)malloc(sizeof(char) * (bufIdx + 1));
            strcpy(result[*returnSize], lineBuffer);
            (*returnSize)++;
            bufIdx = 0;
        }
    }

    return result;
}