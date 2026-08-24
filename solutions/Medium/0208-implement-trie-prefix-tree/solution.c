// ──────────────────────────────────────────────────
// Problem  : 208. Implement Trie (Prefix Tree)
// Difficulty: Medium
// Tags     : Hash Table, String, Design, Trie
// Link     : https://leetcode.com/problems/implement-trie-prefix-tree/
// Runtime  : 22 ms (beats 37%)
// Memory   : 44440000 (beats 17%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct TrieNode {
    struct TrieNode* children[26];
    bool isEnd;
} TrieNode;

typedef struct {
    TrieNode* root;
} Trie;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEnd = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

Trie* trieCreate() {
    Trie* obj = (Trie*)malloc(sizeof(Trie));
    obj->root = createNode();
    return obj;
}

void trieInsert(Trie* obj, char* word) {
    TrieNode* curr = obj->root;
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        if (curr->children[idx] == NULL) {
            curr->children[idx] = createNode();
        }
        curr = curr->children[idx];
    }
    curr->isEnd = true;
}

bool trieSearch(Trie* obj, char* word) {
    TrieNode* curr = obj->root;
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        if (curr->children[idx] == NULL) {
            return false;
        }
        curr = curr->children[idx];
    }
    return curr->isEnd;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    TrieNode* curr = obj->root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int idx = prefix[i] - 'a';
        if (curr->children[idx] == NULL) {
            return false;
        }
        curr = curr->children[idx];
    }
    return true;
}

void freeNode(TrieNode* node) {
    if (node == NULL) return;
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != NULL) {
            freeNode(node->children[i]);
        }
    }
    free(node);
}

void trieFree(Trie* obj) {
    if (obj == NULL) return;
    freeNode(obj->root);
    free(obj);
}