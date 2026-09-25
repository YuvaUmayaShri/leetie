// ──────────────────────────────────────────────────
// Problem  : 1970. Last Day Where You Can Still Cross
// Difficulty: Hard
// Tags     : Array, Binary Search, Depth-First Search, Breadth-First Search, Union-Find, Matrix
// Link     : https://leetcode.com/problems/last-day-where-you-can-still-cross/
// Runtime  : 345 ms (beats 0%)
// Memory   : 159820000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <stdbool.h>

bool canCross(int row, int col, int** cells, int day) {
    int** grid = (int**)malloc(row * sizeof(int*));
    int** visited = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        grid[i] = (int*)calloc(col, sizeof(int));
        visited[i] = (int*)calloc(col, sizeof(int));
    }

    for (int i = 0; i < day; i++) {
        grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
    }

    int* queue = (int*)malloc(row * col * 2 * sizeof(int));
    int head = 0, tail = 0;

    for (int c = 0; c < col; c++) {
        if (grid[0][c] == 0) {
            queue[tail++] = 0;
            queue[tail++] = c;
            visited[0][c] = 1;
        }
    }

    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool possible = false;

    while (head < tail) {
        int r = queue[head++];
        int c = queue[head++];

        if (r == row - 1) {
            possible = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];

            if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0 && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                queue[tail++] = nr;
                queue[tail++] = nc;
            }
        }
    }

    for (int i = 0; i < row; i++) {
        free(grid[i]);
        free(visited[i]);
    }
    free(grid);
    free(visited);
    free(queue);

    return possible;
}

int latestDayToCross(int row, int col, int** cells, int cellsSize, int* cellsColSize) {
    int left = 1;
    int right = cellsSize;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canCross(row, col, cells, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}