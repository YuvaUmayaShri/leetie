// ──────────────────────────────────────────────────
// Problem  : 2069. Walking Robot Simulation II
// Difficulty: Medium
// Tags     : Design, Simulation
// Link     : https://leetcode.com/problems/walking-robot-simulation-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8708000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct {
    int width;
    int height;
    int perimeter;
    int pos;
    bool moved;
} Robot;

Robot* robotCreate(int width, int height) {
    Robot* obj = (Robot*)malloc(sizeof(Robot));
    obj->width = width;
    obj->height = height;
    obj->perimeter = 2 * (width + height - 2);
    obj->pos = 0;
    obj->moved = false;
    return obj;
}

void robotStep(Robot* obj, int num) {
    obj->moved = true;
    obj->pos = (obj->pos + num) % obj->perimeter;
}

int* robotGetPos(Robot* obj, int* retSize) {
    *retSize = 2;
    int* res = (int*)malloc(2 * sizeof(int));
    int w = obj->width;
    int h = obj->height;
    int p = obj->pos;

    if (p < w) {
        res[0] = p;
        res[1] = 0;
    } else if (p < w + h - 1) {
        res[0] = w - 1;
        res[1] = p - (w - 1);
    } else if (p < 2 * w + h - 2) {
        res[0] = (w - 1) - (p - (w + h - 2));
        res[1] = h - 1;
    } else {
        res[0] = 0;
        res[1] = (h - 1) - (p - (2 * w + h - 3));
    }
    return res;
}

char* robotGetDir(Robot* obj) {
    if (!obj->moved) {
        return "East";
    }
    
    int w = obj->width;
    int h = obj->height;
    int p = obj->pos;

    if (p == 0) {
        return "South";
    } else if (p > 0 && p < w) {
        return "East";
    } else if (p >= w && p < w + h - 1) {
        return "North";
    } else if (p >= w + h - 1 && p < 2 * w + h - 2) {
        return "West";
    } else {
        return "South";
    }
}

void robotFree(Robot* obj) {
    free(obj);
}