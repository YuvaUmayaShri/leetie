// ──────────────────────────────────────────────────
// Problem  : 472. Concatenated Words
// Difficulty: Hard
// Tags     : Array, String, Dynamic Programming, Depth-First Search, Trie, Sorting
// Link     : https://leetcode.com/problems/concatenated-words/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8568000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    bool is_end;
} TrieNode;

static TrieNode* createNode(void) {
    TrieNode* node = (TrieNode*)calloc(1, sizeof(TrieNode));
    return node;
}

static void insert(TrieNode* root, const char* word) {
    TrieNode* curr = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        if (!curr->children[idx]) {
            curr->children[idx] = createNode();
        }
        curr = curr->children[idx];
    }
    curr->is_end = true;
}

static bool canForm(TrieNode* root, const char* word, int start, int count, int len, int* memo) {
    if (start == len) {
        return count >= 2;
    }
    if (memo[start] != -1) {
        return memo[start];
    }

    TrieNode* curr = root;
    for (int i = start; i < len; i++) {
        int idx = word[i] - 'a';
        if (!curr->children[idx]) {
            break;
        }
        curr = curr->children[idx];
        if (curr->is_end) {
            if (canForm(root, word, i + 1, count + 1, len, memo)) {
                memo[start] = 1;
                return true;
            }
        }
    }

    memo[start] = 0;
    return false;
}

static void freeTrie(TrieNode* root) {
    if (!root) return;
    for (int i = 0; i < 26; i++) {
        if (root->children[i]) {
            freeTrie(root->children[i]);
        }
    }
    free(root);
}

char** findAllConcatenatedWordsInADict(char** words, int wordsSize, int* returnSize) {
    TrieNode* root = createNode();
    for (int i = 0; i < wordsSize; i++) {
        if (strlen(words[i]) > 0) {
            insert(root, words[i]);
        }
    }

    char** result = (char**)malloc(wordsSize * sizeof(char*));
    int count = 0;

    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]);
        if (len == 0) continue;

        int* memo = (int*)malloc((len + 1) * sizeof(int));
        for (int j = 0; j <= len; j++) memo[j] = -1;

        if (canForm(root, words[i], 0, 0, len, memo)) {
            result[count] = (char*)malloc((len + 1) * sizeof(char));
            strcpy(result[count], words[i]);
            count++;
        }

        free(memo);
    }

    freeTrie(root);
    *returnSize = count;
    return result;
}