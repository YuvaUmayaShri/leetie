// ──────────────────────────────────────────────────
// Problem  : 497. Random Point in Non-overlapping Rectangles
// Difficulty: Medium
// Tags     : Array, Math, Binary Search, Reservoir Sampling, Prefix Sum, Ordered Set, Randomized
// Link     : https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
// Runtime  : 5 ms (beats 72%)
// Memory   : 33984000 (beats 69%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct {
    int** rects;
    int rectsSize;
    int* psum;
    int totalPoints;
} Solution;

Solution* solutionCreate(int** rects, int rectsSize, int* rectsColSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->rects = rects;
    obj->rectsSize = rectsSize;
    obj->psum = (int*)malloc(sizeof(int) * rectsSize);
    
    int currentSum = 0;
    for (int i = 0; i < rectsSize; i++) {
        int width = rects[i][2] - rects[i][0] + 1;
        int height = rects[i][3] - rects[i][1] + 1;
        currentSum += width * height;
        obj->psum[i] = currentSum;
    }
    obj->totalPoints = currentSum;
    return obj;
}

int* solutionPick(Solution* obj, int* retSize) {
    *retSize = 2;
    int target = rand() % obj->totalPoints + 1;
    
    int low = 0, high = obj->rectsSize - 1;
    int rectIdx = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (obj->psum[mid] >= target) {
            rectIdx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    int* rect = obj->rects[rectIdx];
    int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
    
    int* ans = (int*)malloc(sizeof(int) * 2);
    ans[0] = x1 + rand() % (x2 - x1 + 1);
    ans[1] = y1 + rand() % (y2 - y1 + 1);
    
    return ans;
}

void solutionFree(Solution* obj) {
    free(obj->psum);
    free(obj);
}