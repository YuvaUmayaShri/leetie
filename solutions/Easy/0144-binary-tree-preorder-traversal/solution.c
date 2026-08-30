// ──────────────────────────────────────────────────
// Problem  : 144. Binary Tree Preorder Traversal
// Difficulty: Easy
// Tags     : Stack, Tree, Depth-First Search, Binary Tree
// Link     : https://leetcode.com/problems/binary-tree-preorder-traversal/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9452000 (beats 13%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

void helper(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;
    
    result[(*returnSize)++] = root->val;
    helper(root->left, result, returnSize);
    helper(root->right, result, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    
    helper(root, result, returnSize);
    
    return result;
}