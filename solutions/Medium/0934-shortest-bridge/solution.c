// ──────────────────────────────────────────────────
// Problem  : 934. Shortest Bridge
// Difficulty: Medium
// Tags     : Array, Depth-First Search, Breadth-First Search, Matrix
// Link     : https://leetcode.com/problems/shortest-bridge/
// Runtime  : 4 ms (beats 36%)
// Memory   : 12792000 (beats 45%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct {
    int r;
    int c;
} Point;

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int** grid, int n, int r, int c, Point* queue, int* rear) {
    grid[r][c] = 2;
    queue[*rear].r = r;
    queue[*rear].c = c;
    (*rear)++;

    for (int i = 0; i < 4; i++) {
        int nr = r + dirs[i][0];
        int nc = c + dirs[i][1];

        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
            dfs(grid, n, nr, nc, queue, rear);
        }
    }
}

int shortestBridge(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    Point* queue = (Point*)malloc(n * n * sizeof(Point));
    int front = 0, rear = 0;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (found) break;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                dfs(grid, n, i, j, queue, &rear);
                found = true;
                break;
            }
        }
    }

    int steps = 0;
    while (front < rear) {
        int size = rear - front;
        for (int k = 0; k < size; k++) {
            Point curr = queue[front++];

            for (int i = 0; i < 4; i++) {
                int nr = curr.r + dirs[i][0];
                int nc = curr.c + dirs[i][1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    if (grid[nr][nc] == 1) {
                        free(queue);
                        return steps;
                    }
                    if (grid[nr][nc] == 0) {
                        grid[nr][nc] = 2;
                        queue[rear].r = nr;
                        queue[rear].c = nc;
                        rear++;
                    }
                }
            }
        }
        steps++;
    }

    free(queue);
    return steps;
}