// ──────────────────────────────────────────────────
// Problem  : 30. Substring with Concatenation of All Words
// Difficulty: Hard
// Tags     : Hash Table, String, Sliding Window
// Link     : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Runtime  : 1045 ms (beats 14%)
// Memory   : 334776000 (beats 5%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 10007

typedef struct Node {
    char word[31];
    int count;
    struct Node* next;
} Node;

typedef struct {
    Node* buckets[HASH_SIZE];
} HashMap;

unsigned int hash(const char* str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % HASH_SIZE;
}

HashMap* createMap() {
    HashMap* map = (HashMap*)calloc(1, sizeof(HashMap));
    return map;
}

void put(HashMap* map, const char* word) {
    unsigned int idx = hash(word);
    Node* curr = map->buckets[idx];
    while (curr) {
        if (strcmp(curr->word, word) == 0) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = map->buckets[idx];
    map->buckets[idx] = newNode;
}

int get(HashMap* map, const char* word) {
    unsigned int idx = hash(word);
    Node* curr = map->buckets[idx];
    while (curr) {
        if (strcmp(curr->word, word) == 0) {
            return curr->count;
        }
        curr = curr->next;
    }
    return 0;
}

void freeMap(HashMap* map) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = map->buckets[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(map);
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    if (!s || !words || wordsSize == 0) return NULL;

    int sLen = strlen(s);
    int wordLen = strlen(words[0]);
    int totalLen = wordLen * wordsSize;

    if (sLen < totalLen) return NULL;

    HashMap* wordCount = createMap();
    for (int i = 0; i < wordsSize; i++) {
        put(wordCount, words[i]);
    }

    int* result = (int*)malloc(sLen * sizeof(int));

    for (int i = 0; i < wordLen; i++) {
        int left = i, count = 0;
        HashMap* seen = createMap();

        for (int j = i; j <= sLen - wordLen; j += wordLen) {
            char sub[31];
            strncpy(sub, s + j, wordLen);
            sub[wordLen] = '\0';

            int targetCount = get(wordCount, sub);
            if (targetCount > 0) {
                put(seen, sub);
                count++;

                while (get(seen, sub) > targetCount) {
                    char leftSub[31];
                    strncpy(leftSub, s + left, wordLen);
                    leftSub[wordLen] = '\0';

                    unsigned int idx = hash(leftSub);
                    Node* curr = seen->buckets[idx];
                    while (curr) {
                        if (strcmp(curr->word, leftSub) == 0) {
                            curr->count--;
                            break;
                        }
                        curr = curr->next;
                    }

                    count--;
                    left += wordLen;
                }

                if (count == wordsSize) {
                    result[(*returnSize)++] = left;
                }
            } else {
                freeMap(seen);
                seen = createMap();
                count = 0;
                left = j + wordLen;
            }
        }
        freeMap(seen);
    }

    freeMap(wordCount);
    return result;
}