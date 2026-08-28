// ──────────────────────────────────────────────────
// Problem  : 207. Course Schedule
// Difficulty: Medium
// Tags     : Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort, Directed Acyclic Graph
// Link     : https://leetcode.com/problems/course-schedule/
// Runtime  : 4 ms (beats 61%)
// Memory   : 12748000 (beats 47%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct Node {
    int val;
    struct Node* next;
} Node;

void addEdge(Node** adj, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    Node** adj = (Node**)calloc(numCourses, sizeof(Node*));
    int* inDegree = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];
        addEdge(adj, u, v);
        inDegree[v]++;
    }

    int* queue = (int*)malloc(numCourses * sizeof(int));
    int head = 0, tail = 0;

    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[tail++] = i;
        }
    }

    int count = 0;

    while (head < tail) {
        int u = queue[head++];
        count++;

        Node* curr = adj[u];
        while (curr != NULL) {
            int v = curr->val;
            inDegree[v]--;
            if (inDegree[v] == 0) {
                queue[tail++] = v;
            }
            curr = curr->next;
        }
    }

    for (int i = 0; i < numCourses; i++) {
        Node* curr = adj[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(adj);
    free(inDegree);
    free(queue);

    return count == numCourses;
}