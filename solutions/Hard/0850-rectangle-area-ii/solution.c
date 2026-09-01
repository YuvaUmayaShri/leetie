// ──────────────────────────────────────────────────
// Problem  : 850. Rectangle Area II
// Difficulty: Hard
// Tags     : Array, Segment Tree, Sweep Line, Ordered Set
// Link     : https://leetcode.com/problems/rectangle-area-ii/
// Runtime  : 1 ms (beats 80%)
// Memory   : 9820000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    int x;
    int y1;
    int y2;
    int type; // +1 for start, -1 for end
} Event;

int cmpEvents(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    return e1->x - e2->x;
}

int cmpInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int rectangleArea(int** rectangles, int rectanglesSize, int* rectanglesColSize) {
    Event* events = (Event*)malloc(2 * rectanglesSize * sizeof(Event));
    int* y_coords = (int*)malloc(2 * rectanglesSize * sizeof(int));
    int event_cnt = 0;
    int y_cnt = 0;

    for (int i = 0; i < rectanglesSize; i++) {
        int x1 = rectangles[i][0];
        int y1 = rectangles[i][1];
        int x2 = rectangles[i][2];
        int y2 = rectangles[i][3];

        events[event_cnt++] = (Event){x1, y1, y2, 1};
        events[event_cnt++] = (Event){x2, y1, y2, -1};

        y_coords[y_cnt++] = y1;
        y_coords[y_cnt++] = y2;
    }

    qsort(events, event_cnt, sizeof(Event), cmpEvents);
    qsort(y_coords, y_cnt, sizeof(int), cmpInts);

    // Remove duplicates from sorted y_coords
    int unique_y_cnt = 0;
    for (int i = 0; i < y_cnt; i++) {
        if (i == 0 || y_coords[i] != y_coords[i - 1]) {
            y_coords[unique_y_cnt++] = y_coords[i];
        }
    }

    int* active_counts = (int*)calloc(unique_y_cnt - 1, sizeof(int));
    long long total_area = 0;
    long long prev_x = events[0].x;

    for (int i = 0; i < event_cnt; i++) {
        long long current_x = events[i].x;
        long long delta_x = current_x - prev_x;

        if (delta_x > 0) {
            long long current_y_len = 0;
            for (int j = 0; j < unique_y_cnt - 1; j++) {
                if (active_counts[j] > 0) {
                    current_y_len += (long long)y_coords[j + 1] - y_coords[j];
                }
            }
            total_area = (total_area + (delta_x * current_y_len) % MOD) % MOD;
        }

        // Update interval coverage for the current event
        for (int j = 0; j < unique_y_cnt - 1; j++) {
            if (events[i].y1 <= y_coords[j] && y_coords[j + 1] <= events[i].y2) {
                active_counts[j] += events[i].type;
            }
        }

        prev_x = current_x;
    }

    free(events);
    free(y_coords);
    free(active_counts);

    return (int)total_area;
}