// ──────────────────────────────────────────────────
// Problem  : 743. Network Delay Time
// Difficulty: Medium
// Tags     : Depth-First Search, Breadth-First Search, Graph Theory, Heap (Priority Queue), Shortest Path, Dijkstra's Algorithm
// Link     : https://leetcode.com/problems/network-delay-time/
// Runtime  : 87 ms (beats 43%)
// Memory   : 14688000 (beats 83%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#define INF 1e9

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int dist[n + 1];
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[k] = 0;

    for (int i = 1; i < n; i++) {
        int updated = 0;
        for (int j = 0; j < timesSize; j++) {
            int u = times[j][0];
            int v = times[j][1];
            int w = times[j][2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = 1;
            }
        }
        if (!updated) break;
    }

    int maxDist = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) return -1;
        if (dist[i] > maxDist) {
            maxDist = dist[i];
        }
    }

    return maxDist;
}