// ──────────────────────────────────────────────────
// Problem  : 884. Uncommon Words from Two Sentences
// Difficulty: Easy
// Tags     : Hash Table, String, Counting
// Link     : https://leetcode.com/problems/uncommon-words-from-two-sentences/
// Runtime  : 1 ms (beats 19%)
// Memory   : 9268000 (beats 60%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct {
    char word[201];
    int count;
} WordCount;

char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    WordCount counts[400];
    int countsSize = 0;

    char combined[402];
    snprintf(combined, sizeof(combined), "%s %s", s1, s2);

    char* token = strtok(combined, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < countsSize; i++) {
            if (strcmp(counts[i].word, token) == 0) {
                counts[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(counts[countsSize].word, token);
            counts[countsSize].count = 1;
            countsSize++;
        }
        token = strtok(NULL, " ");
    }

    char** result = (char**)malloc(sizeof(char*) * countsSize);
    *returnSize = 0;

    for (int i = 0; i < countsSize; i++) {
        if (counts[i].count == 1) {
            result[*returnSize] = (char*)malloc(strlen(counts[i].word) + 1);
            strcpy(result[*returnSize], counts[i].word);
            (*returnSize)++;
        }
    }

    return result;
}