// ──────────────────────────────────────────────────
// Problem  : 783. Minimum Distance Between BST Nodes
// Difficulty: Easy
// Tags     : Tree, Depth-First Search, Breadth-First Search, Binary Search Tree, Binary Tree
// Link     : https://leetcode.com/problems/minimum-distance-between-bst-nodes/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8576000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int* prev, int* minDiff) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left, prev, minDiff);
    
    if (*prev != -1) {
        int diff = root->val - *prev;
        if (diff < *minDiff) {
            *minDiff = diff;
        }
    }
    *prev = root->val;
    
    inorder(root->right, prev, minDiff);
}

int minDiffInBST(struct TreeNode* root) {
    int prev = -1;
    int minDiff = INT_MAX;
    
    inorder(root, &prev, &minDiff);
    
    return minDiff;
}