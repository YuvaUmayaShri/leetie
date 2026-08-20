// ──────────────────────────────────────────────────
// Problem  : 589. N-ary Tree Preorder Traversal
// Difficulty: Easy
// Tags     : Stack, Tree, Depth-First Search
// Link     : https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8664000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

void traverse(struct Node* root, int* result, int* returnSize) {
    if (root == NULL) return;
    
    
    result[(*returnSize)++] = root->val;
    
    
    for (int i = 0; i < root->numChildren; i++) {
        traverse(root->children[i], result, returnSize);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;
    
    
    int* result = (int*)malloc(10000 * sizeof(int));
    
    traverse(root, result, returnSize);
    
    return result;
}