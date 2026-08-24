// ──────────────────────────────────────────────────
// Problem  : 872. Leaf-Similar Trees
// Difficulty: Easy
// Tags     : Tree, Depth-First Search, Binary Tree
// Link     : https://leetcode.com/problems/leaf-similar-trees/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8664000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

void getLeaves(struct TreeNode* root, int* leaves, int* size) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        leaves[(*size)++] = root->val;
        return;
    }
    getLeaves(root->left, leaves, size);
    getLeaves(root->right, leaves, size);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leaves1[200], size1 = 0;
    int leaves2[200], size2 = 0;

    getLeaves(root1, leaves1, &size1);
    getLeaves(root2, leaves2, &size2);

    if (size1 != size2) {
        return false;
    }

    for (int i = 0; i < size1; i++) {
        if (leaves1[i] != leaves2[i]) {
            return false;
        }
    }

    return true;
}