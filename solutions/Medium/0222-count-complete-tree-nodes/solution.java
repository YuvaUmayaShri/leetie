// ──────────────────────────────────────────────────
// Problem  : 222. Count Complete Tree Nodes
// Difficulty: Medium
// Tags     : Binary Search, Bit Manipulation, Tree, Binary Tree
// Link     : https://leetcode.com/problems/count-complete-tree-nodes/
// Runtime  : 0 ms (beats 100%)
// Memory   : 49108000 (beats 94%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int leftDepth = getLeftDepth(root);
        int rightDepth = getRightDepth(root);

        if (leftDepth == rightDepth) {
            return (1 << leftDepth) - 1;
        }

        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    private int getLeftDepth(TreeNode node) {
        int depth = 0;
        while (node != null) {
            depth++;
            node = node.left;
        }
        return depth;
    }

    private int getRightDepth(TreeNode node) {
        int depth = 0;
        while (node != null) {
            depth++;
            node = node.right;
        }
        return depth;
    }
}