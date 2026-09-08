// ──────────────────────────────────────────────────
// Problem  : 797. All Paths From Source to Target
// Difficulty: Medium
// Tags     : Backtracking, Depth-First Search, Breadth-First Search, Graph Theory, Directed Acyclic Graph
// Link     : https://leetcode.com/problems/all-paths-from-source-to-target/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8564000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

void dfs(int** graph, int graphSize, int* graphColSize, int curr, int* path, int pathSize, int*** result, int* resultSize, int* capacity, int** returnColumnSizes) {
    path[pathSize] = curr;
    pathSize++;

    if (curr == graphSize - 1) {
        if (*resultSize == *capacity) {
            *capacity *= 2;
            *result = (int**)realloc(*result, sizeof(int*) * (*capacity));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * (*capacity));
        }
        (*result)[*resultSize] = (int*)malloc(sizeof(int) * pathSize);
        for (int i = 0; i < pathSize; i++) {
            (*result)[*resultSize][i] = path[i];
        }
        (*returnColumnSizes)[*resultSize] = pathSize;
        (*resultSize)++;
        return;
    }

    for (int i = 0; i < graphColSize[curr]; i++) {
        dfs(graph, graphSize, graphColSize, graph[curr][i], path, pathSize, result, resultSize, capacity, returnColumnSizes);
    }
}

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes) {
    int capacity = 1000;
    *returnSize = 0;
    
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    
    int path[15];
    dfs(graph, graphSize, graphColSize, 0, path, 0, &result, returnSize, &capacity, returnColumnSizes);
    
    return result;
}