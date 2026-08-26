// ──────────────────────────────────────────────────
// Problem  : 542. 01 Matrix
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Breadth-First Search, Matrix
// Link     : https://leetcode.com/problems/01-matrix/
// Runtime  : 14 ms (beats 72%)
// Memory   : 49276000 (beats 44%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        
        Queue<int[]> queue = new LinkedList<>();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    queue.offer(new int[]{i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }
        
        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int r = curr[0];
            int c = curr[1];
            
            for (int[] dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] == -1) {
                    mat[nr][nc] = mat[r][c] + 1;
                    queue.offer(new int[]{nr, nc});
                }
            }
        }
        
        return mat;
    }
}