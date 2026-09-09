// ──────────────────────────────────────────────────
// Problem  : 107. Binary Tree Level Order Traversal II
// Difficulty: Medium
// Tags     : Tree, Breadth-First Search, Binary Tree
// Link     : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12936000 (beats 82%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int** result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
    int levels = 0;

    while (front < rear) {
        int levelSize = rear - front;
        result[levels] = (int*)malloc(sizeof(int) * levelSize);
        (*returnColumnSizes)[levels] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            result[levels][i] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        levels++;
    }

    *returnSize = levels;

    for (int i = 0; i < levels / 2; i++) {
        int* tempArr = result[i];
        result[i] = result[levels - 1 - i];
        result[levels - 1 - i] = tempArr;

        int tempCol = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[levels - 1 - i];
        (*returnColumnSizes)[levels - 1 - i] = tempCol;
    }

    return result;
}