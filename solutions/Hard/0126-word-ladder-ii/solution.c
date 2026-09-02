// ──────────────────────────────────────────────────
// Problem  : 126. Word Ladder II
// Difficulty: Hard
// Tags     : Hash Table, String, Backtracking, Breadth-First Search, Bidirectional Search
// Link     : https://leetcode.com/problems/word-ladder-ii/
// Runtime  : 11 ms (beats 31%)
// Memory   : 10816000 (beats 64%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int wordIdx;
    struct Node* next;
} Node;

typedef struct QueueNode {
    int wordIdx;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

static void pushQueue(Queue* q, int val) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->wordIdx = val;
    node->next = NULL;
    if (q->rear) {
        q->rear->next = node;
        q->rear = node;
    } else {
        q->front = q->rear = node;
    }
}

static int popQueue(Queue* q) {
    if (!q->front) return -1;
    QueueNode* temp = q->front;
    int val = temp->wordIdx;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return val;
}

static bool isOneDiff(const char* a, const char* b, int len) {
    int diff = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return false;
        }
    }
    return diff == 1;
}

static void dfs(int u, int target, char** words, Node** parents, char** path, int pathLen, char**** res, int* resCap, int* resSize, int** colSizes) {
    path[pathLen] = words[u];
    
    if (u == target) {
        if (*resSize >= *resCap) {
            *resCap *= 2;
            *res = (char***)realloc(*res, (*resCap) * sizeof(char**));
            *colSizes = (int*)realloc(*colSizes, (*resCap) * sizeof(int));
        }
        
        char** singlePath = (char**)malloc((pathLen + 1) * sizeof(char*));
        for (int i = 0; i <= pathLen; i++) {
            singlePath[i] = path[pathLen - i];
        }
        
        (*res)[*resSize] = singlePath;
        (*colSizes)[*resSize] = pathLen + 1;
        (*resSize)++;
        return;
    }
    
    Node* curr = parents[u];
    while (curr) {
        dfs(curr->wordIdx, target, words, parents, path, pathLen + 1, res, resCap, resSize, colSizes);
        curr = curr->next;
    }
}

char*** findLadders(char* beginWord, char* endWord, char** wordList, int wordListSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    
    int endIdx = -1;
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(wordList[i], endWord) == 0) {
            endIdx = i;
            break;
        }
    }
    if (endIdx == -1) return NULL;

    int totalWords = wordListSize + 1;
    char** allWords = (char**)malloc(totalWords * sizeof(char*));
    allWords[0] = beginWord;
    for (int i = 0; i < wordListSize; i++) {
        allWords[i + 1] = wordList[i];
    }
    endIdx++;

    int wordLen = strlen(beginWord);
    Node** parents = (Node**)calloc(totalWords, sizeof(Node*));
    int* dist = (int*)malloc(totalWords * sizeof(int));
    for (int i = 0; i < totalWords; i++) dist[i] = 1e9;
    
    dist[0] = 0;
    Queue q = {NULL, NULL};
    pushQueue(&q, 0);

    while (q.front) {
        int u = popQueue(&q);
        
        for (int v = 0; v < totalWords; v++) {
            if (isOneDiff(allWords[u], allWords[v], wordLen)) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    pushQueue(&q, v);
                    
                    Node* pNode = (Node*)malloc(sizeof(Node));
                    pNode->wordIdx = u;
                    pNode->next = NULL;
                    parents[v] = pNode;
                } else if (dist[v] == dist[u] + 1) {
                    Node* pNode = (Node*)malloc(sizeof(Node));
                    pNode->wordIdx = u;
                    pNode->next = parents[v];
                    parents[v] = pNode;
                }
            }
        }
    }

    if (dist[endIdx] == 1e9) {
        free(allWords);
        free(dist);
        free(parents);
        return NULL;
    }

    int resCap = 1000;
    char*** res = (char***)malloc(resCap * sizeof(char**));
    *returnColumnSizes = (int*)malloc(resCap * sizeof(int));
    char** path = (char**)malloc(totalWords * sizeof(char*));

    dfs(endIdx, 0, allWords, parents, path, 0, &res, &resCap, returnSize, returnColumnSizes);

    free(path);
    free(allWords);
    free(dist);
    return res;
}