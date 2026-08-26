// ──────────────────────────────────────────────────
// Problem  : 538. Convert BST to Greater Tree
// Difficulty: Medium
// Tags     : Tree, Depth-First Search, Binary Search Tree, Binary Tree
// Link     : https://leetcode.com/problems/convert-bst-to-greater-tree/
// Runtime  : 0 ms (beats 100%)
// Memory   : 47316000 (beats 63%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    private int sum = 0;

    public TreeNode convertBST(TreeNode root) {
        if (root != null) {
            convertBST(root.right);
            sum += root.val;
            root.val = sum;
            convertBST(root.left);
        }
        return root;
    }
}