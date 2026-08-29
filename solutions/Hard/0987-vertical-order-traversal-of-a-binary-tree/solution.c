// ──────────────────────────────────────────────────
// Problem  : 987. Vertical Order Traversal of a Binary Tree
// Difficulty: Hard
// Tags     : Hash Table, Tree, Depth-First Search, Breadth-First Search, Sorting, Binary Tree
// Link     : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8928000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

struct NodeData {
    int col;
    int row;
    int val;
};

void dfs(struct TreeNode* root, int row, int col, struct NodeData* nodes, int* count) {
    if (!root) return;
    nodes[*count].row = row;
    nodes[*count].col = col;
    nodes[*count].val = root->val;
    (*count)++;
    dfs(root->left, row + 1, col - 1, nodes, count);
    dfs(root->right, row + 1, col + 1, nodes, count);
}

int compare(const void* a, const void* b) {
    struct NodeData* n1 = (struct NodeData*)a;
    struct NodeData* n2 = (struct NodeData*)b;
    if (n1->col != n2->col) return n1->col - n2->col;
    if (n1->row != n2->row) return n1->row - n2->row;
    return n1->val - n2->val;
}

int** verticalTraversal(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    struct NodeData nodes[1000];
    int count = 0;
    dfs(root, 0, 0, nodes, &count);

    qsort(nodes, count, sizeof(struct NodeData), compare);

    int** res = (int**)malloc(count * sizeof(int*));
    *returnColumnSizes = (int*)malloc(count * sizeof(int));
    *returnSize = 0;

    int i = 0;
    while (i < count) {
        int j = i;
        while (j < count && nodes[j].col == nodes[i].col) {
            j++;
        }
        int colSize = j - i;
        res[*returnSize] = (int*)malloc(colSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = colSize;

        for (int k = 0; k < colSize; k++) {
            res[*returnSize][k] = nodes[i + k].val;
        }

        (*returnSize)++;
        i = j;
    }

    return res;
}