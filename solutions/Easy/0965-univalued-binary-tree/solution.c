// ──────────────────────────────────────────────────
// Problem  : 965. Univalued Binary Tree
// Difficulty: Easy
// Tags     : Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Link     : https://leetcode.com/problems/univalued-binary-tree/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9404000 (beats 27%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool isUnivalTree(struct TreeNode* root) {
    if (!root) return true;
    
    if (root->left && root->left->val != root->val) return false;
    if (root->right && root->right->val != root->val) return false;
    
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}