// ──────────────────────────────────────────────────
// Problem  : 435. Non-overlapping Intervals
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Greedy, Sorting
// Link     : https://leetcode.com/problems/non-overlapping-intervals/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8464000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    if (intervalA[1] == intervalB[1]) {
        return intervalA[0] - intervalB[0];
    }
    return (intervalA[1] > intervalB[1]) ? 1 : -1;
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize <= 0) {
        return 0;
    }
    
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    
    int count = 0;
    int end = intervals[0][1];
    
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < end) {
            count++;
        } else {
            end = intervals[i][1];
        }
    }
    
    return count;
}