// ──────────────────────────────────────────────────
// Problem  : 436. Find Right Interval
// Difficulty: Medium
// Tags     : Array, Binary Search, Sorting
// Link     : https://leetcode.com/problems/find-right-interval/
// Runtime  : 3 ms (beats 80%)
// Memory   : 21684000 (beats 24%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct {
    int start;
    int index;
} IntervalStart;

int compare(const void* a, const void* b) {
    return ((IntervalStart*)a)->start - ((IntervalStart*)b)->start;
}

int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize) {
    *returnSize = intervalsSize;
    int* result = (int*)malloc(intervalsSize * sizeof(int));
    IntervalStart* starts = (IntervalStart*)malloc(intervalsSize * sizeof(IntervalStart));
    
    for (int i = 0; i < intervalsSize; i++) {
        starts[i].start = intervals[i][0];
        starts[i].index = i;
    }
    
    qsort(starts, intervalsSize, sizeof(IntervalStart), compare);
    
    for (int i = 0; i < intervalsSize; i++) {
        int target = intervals[i][1];
        int low = 0, high = intervalsSize - 1;
        int rightIndex = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (starts[mid].start >= target) {
                rightIndex = starts[mid].index;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        result[i] = rightIndex;
    }
    
    free(starts);
    return result;
}