// ──────────────────────────────────────────────────
// Problem  : 124. Binary Tree Maximum Path Sum
// Difficulty: Hard
// Tags     : Dynamic Programming, Tree, Depth-First Search, Binary Tree, DP on Trees
// Link     : https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Runtime  : 0 ms (beats 100%)
// Memory   : 17608000 (beats 69%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxGain(struct TreeNode* node, int* maxSum) {
    if (node == NULL) {
        return 0;
    }

    int leftGain = max(maxGain(node->left, maxSum), 0);
    int rightGain = max(maxGain(node->right, maxSum), 0);

    int currentPathSum = node->val + leftGain + rightGain;

    if (currentPathSum > *maxSum) {
        *maxSum = currentPathSum;
    }

    return node->val + max(leftGain, rightGain);
}

int maxPathSum(struct TreeNode* root) {
    int maxSum = INT_MIN;
    maxGain(root, &maxSum);
    return maxSum;
}