// ──────────────────────────────────────────────────
// Problem  : 129. Sum Root to Leaf Numbers
// Difficulty: Medium
// Tags     : Tree, Depth-First Search, Binary Tree
// Link     : https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8276000 (beats 0%)
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