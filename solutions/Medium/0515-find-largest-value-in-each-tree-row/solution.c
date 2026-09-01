// ──────────────────────────────────────────────────
// Problem  : 515. Find Largest Value in Each Tree Row
// Difficulty: Medium
// Tags     : Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Link     : https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// Runtime  : 0 ms (beats 100%)
// Memory   : 16432000 (beats 18%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) return NULL;
    
    int capacity = 1000;
    int* result = (int*)malloc(capacity * sizeof(int));
    
    struct TreeNode** queue = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    
    queue[tail++] = root;
    
    while (head < tail) {
        int levelSize = tail - head;
        int maxVal = INT_MIN;
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            if (node->val > maxVal) {
                maxVal = node->val;
            }
            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }
        
        if (*returnSize >= capacity) {
            capacity *= 2;
            result = (int*)realloc(result, capacity * sizeof(int));
        }
        result[(*returnSize)++] = maxVal;
    }
    
    free(queue);
    return result;
}