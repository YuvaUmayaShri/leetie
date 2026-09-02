// ──────────────────────────────────────────────────
// Problem  : 127. Word Ladder
// Difficulty: Hard
// Tags     : Hash Table, String, Breadth-First Search, Bidirectional Search
// Link     : https://leetcode.com/problems/word-ladder/
// Runtime  : 187 ms (beats 90%)
// Memory   : 10816000 (beats 20%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int wordIdx;
    int dist;
} QueueNode;

typedef struct {
    QueueNode* data;
    int front;
    int rear;
} Queue;

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    int endIdx = -1;
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(wordList[i], endWord) == 0) {
            endIdx = i;
            break;
        }
    }
    if (endIdx == -1) return 0;

    int totalWords = wordListSize + 1;
    char** allWords = (char**)malloc(totalWords * sizeof(char*));
    allWords[0] = beginWord;
    for (int i = 0; i < wordListSize; i++) {
        allWords[i + 1] = wordList[i];
    }
    endIdx++;

    bool* visited = (bool*)calloc(totalWords, sizeof(bool));
    Queue q;
    q.data = (QueueNode*)malloc(totalWords * sizeof(QueueNode));
    q.front = 0;
    q.rear = 0;

    q.data[q.rear++] = (QueueNode){0, 1};
    visited[0] = true;

    int wordLen = strlen(beginWord);

    while (q.front < q.rear) {
        QueueNode curr = q.data[q.front++];

        if (curr.wordIdx == endIdx) {
            free(allWords);
            free(visited);
            free(q.data);
            return curr.dist;
        }

        char* currWord = allWords[curr.wordIdx];

        for (int i = 0; i < totalWords; i++) {
            if (visited[i]) continue;

            int diff = 0;
            char* targetWord = allWords[i];
            for (int j = 0; j < wordLen; j++) {
                if (currWord[j] != targetWord[j]) {
                    diff++;
                    if (diff > 1) break;
                }
            }

            if (diff == 1) {
                visited[i] = true;
                q.data[q.rear++] = (QueueNode){i, curr.dist + 1};
            }
        }
    }

    free(allWords);
    free(visited);
    free(q.data);
    return 0;
}