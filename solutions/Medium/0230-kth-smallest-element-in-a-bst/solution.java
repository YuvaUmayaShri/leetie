// ──────────────────────────────────────────────────
// Problem  : 230. Kth Smallest Element in a BST
// Difficulty: Medium
// Tags     : Tree, Depth-First Search, Binary Search Tree, Binary Tree
// Link     : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Runtime  : 0 ms (beats 100%)
// Memory   : 47092000 (beats 6%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    private int count = 0;
    private int result = 0;

    public int kthSmallest(TreeNode root, int k) {
        count = k;
        inorder(root);
        return result;
    }

    private void inorder(TreeNode node) {
        if (node == null) {
            return;
        }

        inorder(node.left);

        count--;
        if (count == 0) {
            result = node.val;
            return;
        }

        inorder(node.right);
    }
}