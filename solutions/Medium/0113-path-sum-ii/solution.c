// ──────────────────────────────────────────────────
// Problem  : 113. Path Sum II
// Difficulty: Medium
// Tags     : Backtracking, Tree, Depth-First Search, Binary Tree
// Link     : https://leetcode.com/problems/path-sum-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 13896000 (beats 97%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

void dfs(struct TreeNode* root, int targetSum, int* currentPath, int pathLen, int*** result, int** returnColumnSizes, int* returnSize, int* capacity) {
    if (!root) return;

    currentPath[pathLen] = root->val;
    pathLen++;
    targetSum -= root->val;

    if (!root->left && !root->right && targetSum == 0) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = (int**)realloc(*result, sizeof(int*) * (*capacity));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * (*capacity));
        }

        (*result)[*returnSize] = (int*)malloc(sizeof(int) * pathLen);
        for (int i = 0; i < pathLen; i++) {
            (*result)[*returnSize][i] = currentPath[i];
        }
        (*returnColumnSizes)[*returnSize] = pathLen;
        (*returnSize)++;
        return;
    }

    dfs(root->left, targetSum, currentPath, pathLen, result, returnColumnSizes, returnSize, capacity);
    dfs(root->right, targetSum, currentPath, pathLen, result, returnColumnSizes, returnSize, capacity);
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int capacity = 10;

    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    int currentPath[5000];

    dfs(root, targetSum, currentPath, 0, &result, returnColumnSizes, returnSize, &capacity);

    return result;
}