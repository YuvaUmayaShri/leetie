// ──────────────────────────────────────────────────
// Problem  : 835. Image Overlap
// Difficulty: Medium
// Tags     : Array, Matrix
// Link     : https://leetcode.com/problems/image-overlap/
// Runtime  : 10 ms (beats 90%)
// Memory   : 10636000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int largestOverlap(int** img1, int img1Size, int* img1ColSize, int** img2, int img2Size, int* img2ColSize) {
    int n = img1Size;
    int max_overlap = 0;
    
    int p1[900][2];
    int p2[900][2];
    int count1 = 0, count2 = 0;
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (img1[r][c] == 1) {
                p1[count1][0] = r;
                p1[count1][1] = c;
                count1++;
            }
            if (img2[r][c] == 1) {
                p2[count2][0] = r;
                p2[count2][1] = c;
                count2++;
            }
        }
    }
    
    int freq[61][61] = {0};
    
    for (int i = 0; i < count1; i++) {
        for (int j = 0; j < count2; j++) {
            int dr = p2[j][0] - p1[i][0] + 30;
            int dc = p2[j][1] - p1[i][1] + 30;
            freq[dr][dc]++;
            if (freq[dr][dc] > max_overlap) {
                max_overlap = freq[dr][dc];
            }
        }
    }
    
    return max_overlap;
}