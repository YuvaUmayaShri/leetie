// ──────────────────────────────────────────────────
// Problem  : 129. Sum Root to Leaf Numbers
// Difficulty: Medium
// Tags     : Tree, Depth-First Search, Binary Tree
// Link     : https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9340000 (beats 41%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int dfs(struct TreeNode* node, int currentSum) {
    if (node == NULL) {
        return 0;
    }
    
    currentSum = currentSum * 10 + node->val;
    
    if (node->left == NULL && node->right == NULL) {
        return currentSum;
    }
    
    return dfs(node->left, currentSum) + dfs(node->right, currentSum);
}

int sumNumbers(struct TreeNode* root) {
    return dfs(root, 0);
}