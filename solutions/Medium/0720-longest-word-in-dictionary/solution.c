// ──────────────────────────────────────────────────
// Problem  : 720. Longest Word in Dictionary
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Trie, Sorting
// Link     : https://leetcode.com/problems/longest-word-in-dictionary/
// Runtime  : 12 ms (beats 85%)
// Memory   : 18500000 (beats 36%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;
    return strcmp(str1, str2);
}

typedef struct TrieNode {
    struct TrieNode* children[26];
    bool isEnd;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEnd = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void freeTrie(TrieNode* root) {
    if (!root) return;
    for (int i = 0; i < 26; i++) {
        if (root->children[i]) {
            freeTrie(root->children[i]);
        }
    }
    free(root);
}

char* longestWord(char** words, int wordsSize) {
    qsort(words, wordsSize, sizeof(char*), cmp);

    TrieNode* root = createNode();
    char* result = "";
    int maxLen = 0;

    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]);
        if (len == 1) {
            TrieNode* curr = root;
            int idx = words[i][0] - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = createNode();
            }
            curr->children[idx]->isEnd = true;
            
            if (len > maxLen) {
                maxLen = len;
                result = words[i];
            }
        } else {
            TrieNode* curr = root;
            bool valid = true;
            for (int j = 0; j < len - 1; j++) {
                int idx = words[i][j] - 'a';
                if (!curr->children[idx] || !curr->children[idx]->isEnd) {
                    valid = false;
                    break;
                }
                curr = curr->children[idx];
            }
            if (valid) {
                int idx = words[i][len - 1] - 'a';
                if (!curr->children[idx]) {
                    curr->children[idx] = createNode();
                }
                curr->children[idx]->isEnd = true;

                if (len > maxLen) {
                    maxLen = len;
                    result = words[i];
                }
            }
        }
    }

    freeTrie(root);
    return result;
}