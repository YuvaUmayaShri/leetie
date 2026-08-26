// ──────────────────────────────────────────────────
// Problem  : 671. Second Minimum Node In a Binary Tree
// Difficulty: Easy
// Tags     : Tree, Depth-First Search, Binary Tree
// Link     : https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
// Runtime  : 0 ms (beats 100%)
// Memory   : 42692000 (beats 64%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int findSecondMinimumValue(TreeNode root) {
        if (root == null) {
            return -1;
        }
        return findSecondMin(root, root.val);
    }

    private int findSecondMin(TreeNode node, int minVal) {
        if (node == null) {
            return -1;
        }

        if (node.val > minVal) {
            return node.val;
        }

        int left = findSecondMin(node.left, minVal);
        int right = findSecondMin(node.right, minVal);

        if (left != -1 && right != -1) {
            return Math.min(left, right);
        }

        return left != -1 ? left : right;
    }
}