// ──────────────────────────────────────────────────
// Problem  : 699. Falling Squares
// Difficulty: Hard
// Tags     : Array, Segment Tree, Ordered Set
// Link     : https://leetcode.com/problems/falling-squares/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8448000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int* fallingSquares(int** positions, int positionsSize, int* positionsColSize, int* returnSize) {
    *returnSize = positionsSize;
    int* ans = (int*)malloc(positionsSize * sizeof(int));
    int* heights = (int*)malloc(positionsSize * sizeof(int));
    
    int maxHeight = 0;
    
    for (int i = 0; i < positionsSize; i++) {
        int left1 = positions[i][0];
        int size1 = positions[i][1];
        int right1 = left1 + size1;
        
        int baseHeight = 0;
        
        for (int j = 0; j < i; j++) {
            int left2 = positions[j][0];
            int size2 = positions[j][1];
            int right2 = left2 + size2;
            
            // Check if interval [left1, right1) overlaps with [left2, right2)
            if (left1 < right2 && right1 > left2) {
                baseHeight = MAX(baseHeight, heights[j]);
            }
        }
        
        heights[i] = baseHeight + size1;
        maxHeight = MAX(maxHeight, heights[i]);
        ans[i] = maxHeight;
    }
    
    free(heights);
    return ans;
}