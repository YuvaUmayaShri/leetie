// ──────────────────────────────────────────────────
// Problem  : 235. Lowest Common Ancestor of a Binary Search Tree
// Difficulty: Medium
// Tags     : Tree, Depth-First Search, Binary Search Tree, Binary Tree, Binary Lifting, Lowest Common Ancestor
// Link     : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Runtime  : 6 ms (beats 97%)
// Memory   : 47688000 (beats 55%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        while (root != null) {
            if (p.val < root.val && q.val < root.val) {
                root = root.left;
            } else if (p.val > root.val && q.val > root.val) {
                root = root.right;
            } else {
                return root;
            }
        }
        return null;
    }
}