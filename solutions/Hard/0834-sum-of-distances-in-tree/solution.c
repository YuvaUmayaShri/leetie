// ──────────────────────────────────────────────────
// Problem  : 834. Sum of Distances in Tree
// Difficulty: Hard
// Tags     : Dynamic Programming, Tree, Depth-First Search, Graph Theory, DP on Trees
// Link     : https://leetcode.com/problems/sum-of-distances-in-tree/
// Runtime  : 84 ms (beats 23%)
// Memory   : 65776000 (beats 15%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct Node {
    int neighbor;
    struct Node* next;
} Node;

void addEdge(Node** head, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->neighbor = v;
    newNode->next = head[u];
    head[u] = newNode;
}

void dfs1(Node** head, int u, int parent, int* count, int* ans) {
    count[u] = 1;
    ans[u] = 0;
    Node* curr = head[u];
    while (curr != NULL) {
        int v = curr->neighbor;
        if (v != parent) {
            dfs1(head, v, u, count, ans);
            count[u] += count[v];
            ans[u] += ans[v] + count[v];
        }
        curr = curr->next;
    }
}

void dfs2(Node** head, int u, int parent, int n, int* count, int* ans) {
    Node* curr = head[u];
    while (curr != NULL) {
        int v = curr->neighbor;
        if (v != parent) {
            ans[v] = ans[u] - count[v] + (n - count[v]);
            dfs2(head, v, u, n, count, ans);
        }
        curr = curr->next;
    }
}

int* sumOfDistancesInTree(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    *returnSize = n;
    
    Node** head = (Node**)calloc(n, sizeof(Node*));
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        addEdge(head, u, v);
        addEdge(head, v, u);
    }
    
    int* count = (int*)malloc(n * sizeof(int));
    int* ans = (int*)malloc(n * sizeof(int));
    
    dfs1(head, 0, -1, count, ans);
    dfs2(head, 0, -1, n, count, ans);
    
    for (int i = 0; i < n; i++) {
        Node* curr = head[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(head);
    free(count);
    
    return ans;
}