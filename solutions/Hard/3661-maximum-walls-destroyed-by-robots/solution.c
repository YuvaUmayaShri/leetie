// ──────────────────────────────────────────────────
// Problem  : 3661. Maximum Walls Destroyed by Robots
// Difficulty: Hard
// Tags     : Array, Binary Search, Dynamic Programming, Sorting
// Link     : https://leetcode.com/problems/maximum-walls-destroyed-by-robots/
// Runtime  : 215 ms (beats 89%)
// Memory   : 31320000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

typedef struct {
    int pos;
    int dist;
} Robot;

int compareRobots(const void* a, const void* b) {
    return ((Robot*)a)->pos - ((Robot*)b)->pos;
}

int compareInts(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int countWallsInRange(int* walls, int wallsSize, int left, int right) {
    if (left > right) return 0;

    int l = 0, r = wallsSize - 1, startIdx = wallsSize;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (walls[mid] >= left) {
            startIdx = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    l = 0;
    r = wallsSize - 1;
    int endIdx = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (walls[mid] <= right) {
            endIdx = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (startIdx <= endIdx) {
        return endIdx - startIdx + 1;
    }
    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxWalls(int* robots, int robotsSize, int* distance, int distanceSize, int* walls, int wallsSize) {
    Robot* bot = (Robot*)malloc(robotsSize * sizeof(Robot));
    for (int i = 0; i < robotsSize; i++) {
        bot[i].pos = robots[i];
        bot[i].dist = distance[i];
    }

    qsort(bot, robotsSize, sizeof(Robot), compareRobots);
    qsort(walls, wallsSize, sizeof(int), compareInts);

    int dp_left = 0;
    int dp_right = 0;

    for (int i = 0; i < robotsSize; i++) {
        // Shooting Left
        int left_bound = bot[i].pos - bot[i].dist;
        if (i > 0 && left_bound < bot[i - 1].pos + 1) {
            left_bound = bot[i - 1].pos + 1;
        }
        int walls_left = countWallsInRange(walls, wallsSize, left_bound, bot[i].pos);

        // Shooting Right
        int right_bound = bot[i].pos + bot[i].dist;
        if (i + 1 < robotsSize && right_bound > bot[i + 1].pos - 1) {
            right_bound = bot[i + 1].pos - 1;
        }
        int walls_right = countWallsInRange(walls, wallsSize, bot[i].pos, right_bound);

        // Handle transitions cleanly without overlap double-counting
        int new_dp_left = max(dp_left + walls_left, dp_right + countWallsInRange(walls, wallsSize, max(left_bound, (i > 0 ? bot[i-1].pos + bot[i-1].dist + 1 : left_bound)), bot[i].pos));
        int new_dp_right = max(dp_left + walls_right, dp_right + walls_right);

        dp_left = new_dp_left;
        dp_right = new_dp_right;
    }

    int result = max(dp_left, dp_right);
    free(bot);
    return result;
}