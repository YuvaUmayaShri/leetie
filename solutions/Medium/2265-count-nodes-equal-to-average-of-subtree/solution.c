// ──────────────────────────────────────────────────
// Problem  : 2265. Count Nodes Equal to Average of Subtree
// Difficulty: Medium
// Tags     : Tree, Depth-First Search, Binary Tree
// Link     : https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
// Runtime  : 10 ms (beats 53%)
// Memory   : 12164000 (beats 91%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

struct Result {
    int sum;
    int count;
};

struct Result postOrder(struct TreeNode* node, int* matchingNodes) {
    if (node == NULL) {
        struct Result res = {0, 0};
        return res;
    }

    struct Result left = postOrder(node->left, matchingNodes);
    struct Result right = postOrder(node->right, matchingNodes);

    int totalSum = left.sum + right.sum + node->val;
    int totalCount = left.count + right.count + 1;

    if (node->val == totalSum / totalCount) {
        (*matchingNodes)++;
    }

    struct Result res = {totalSum, totalCount};
    return res;
}

int averageOfSubtree(struct TreeNode* root) {
    int matchingNodes = 0;
    postOrder(root, &matchingNodes);
    return matchingNodes;
}