// ──────────────────────────────────────────────────
// Problem  : 951. Flip Equivalent Binary Trees
// Difficulty: Medium
// Tags     : Tree, Depth-First Search, Binary Tree
// Link     : https://leetcode.com/problems/flip-equivalent-binary-trees/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10044000 (beats 55%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL || root1->val != root2->val) {
        return false;
    }

    bool noFlip = flipEquiv(root1->left, root2->left) && 
                 flipEquiv(root1->right, root2->right);
                 
    bool flip = flipEquiv(root1->left, root2->right) && 
               flipEquiv(root1->right, root2->left);

    return noFlip || flip;
}