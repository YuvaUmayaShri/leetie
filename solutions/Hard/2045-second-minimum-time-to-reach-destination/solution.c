// ──────────────────────────────────────────────────
// Problem  : 2045. Second Minimum Time to Reach Destination
// Difficulty: Hard
// Tags     : Breadth-First Search, Graph Theory, Shortest Path, Dijkstra's Algorithm, K Shortest Path
// Link     : https://leetcode.com/problems/second-minimum-time-to-reach-destination/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8592000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct Node {
    int val;
    struct Node* next;
} Node;

void addEdge(Node** head, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = head[u];
    head[u] = newNode;
}

int secondMinimum(int n, int** edges, int edgesSize, int* edgesColSize, int time, int change) {
    Node** adj = (Node**)calloc(n + 1, sizeof(Node*));
    for (int i = 0; i < edgesSize; i++) {
        addEdge(adj, edges[i][0], edges[i][1]);
        addEdge(adj, edges[i][1], edges[i][0]);
    }

    int* dist1 = (int*)malloc((n + 1) * sizeof(int));
    int* dist2 = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        dist1[i] = -1;
        dist2[i] = -1;
    }

    int* queueNode = (int*)malloc((n * 10) * sizeof(int));
    int* queueDist = (int*)malloc((n * 10) * sizeof(int));
    int head = 0, tail = 0;

    dist1[1] = 0;
    queueNode[tail] = 1;
    queueDist[tail] = 0;
    tail++;

    while (head < tail) {
        int u = queueNode[head];
        int d = queueDist[head];
        head++;

        Node* curr = adj[u];
        while (curr != NULL) {
            int v = curr->val;
            if (dist1[v] == -1) {
                dist1[v] = d + 1;
                queueNode[tail] = v;
                queueDist[tail] = d + 1;
                tail++;
            } else if (dist2[v] == -1 && dist1[v] != d + 1) {
                dist2[v] = d + 1;
                queueNode[tail] = v;
                queueDist[tail] = d + 1;
                tail++;
            }
            curr = curr->next;
        }
    }

    int steps = dist2[n];
    int currentTime = 0;

    for (int i = 0; i < steps; i++) {
        if ((currentTime / change) % 2 == 1) {
            currentTime = (currentTime / change + 1) * change;
        }
        currentTime += time;
    }

    for (int i = 1; i <= n; i++) {
        Node* curr = adj[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(adj);
    free(dist1);
    free(dist2);
    free(queueNode);
    free(queueDist);

    return currentTime;
}