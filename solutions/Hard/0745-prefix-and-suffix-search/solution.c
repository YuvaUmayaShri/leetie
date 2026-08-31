// ──────────────────────────────────────────────────
// Problem  : 745. Prefix and Suffix Search
// Difficulty: Hard
// Tags     : Array, Hash Table, String, Design, Trie
// Link     : https://leetcode.com/problems/prefix-and-suffix-search/
// Runtime  : 367 ms (beats 100%)
// Memory   : 565808000 (beats 8%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode* children[27]; // 26 lowercase letters + 1 for '#'
    int index;
} TrieNode;

typedef struct {
    TrieNode* root;
} WordFilter;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->index = -1;
    for (int i = 0; i < 27; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode* root, const char* str, int index) {
    TrieNode* curr = root;
    for (int i = 0; str[i] != '\0'; i++) {
        int idx = (str[i] == '#') ? 26 : (str[i] - 'a');
        if (!curr->children[idx]) {
            curr->children[idx] = createNode();
        }
        curr = curr->children[idx];
        curr->index = index; // Always update to keep the maximum index
    }
}

WordFilter* wordFilterCreate(char** words, int wordsSize) {
    WordFilter* filter = (WordFilter*)malloc(sizeof(WordFilter));
    filter->root = createNode();

    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]);
        // Insert suffix + '#' + word into Trie for all suffixes
        for (int j = 0; j <= len; j++) {
            char key[202]; // Max length: len + 1 + len + 1
            strcpy(key, words[i] + j);
            strcat(key, "#");
            strcat(key, words[i]);
            insert(filter->root, key, i);
        }
    }
    return filter;
}

int wordFilterF(WordFilter* obj, char* pref, char* suff) {
    char key[202];
    strcpy(key, suff);
    strcat(key, "#");
    strcat(key, pref);

    TrieNode* curr = obj->root;
    for (int i = 0; key[i] != '\0'; i++) {
        int idx = (key[i] == '#') ? 26 : (key[i] - 'a');
        if (!curr->children[idx]) {
            return -1;
        }
        curr = curr->children[idx];
    }
    return curr->index;
}

void freeTrie(TrieNode* node) {
    if (!node) return;
    for (int i = 0; i < 27; i++) {
        if (node->children[i]) {
            freeTrie(node->children[i]);
        }
    }
    free(node);
}

void wordFilterFree(WordFilter* obj) {
    if (obj) {
        freeTrie(obj->root);
        free(obj);
    }
}