// ──────────────────────────────────────────────────
// Problem  : 778. Swim in Rising Water
// Difficulty: Hard
// Tags     : Array, Binary Search, Depth-First Search, Breadth-First Search, Union-Find, Minimax, Heap (Priority Queue), Matrix, Dijkstra's Algorithm
// Link     : https://leetcode.com/problems/swim-in-rising-water/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8856000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int swimInWater(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
        std::priority_queue<std::tuple<int, int, int>, 
                            std::vector<std::tuple<int, int, int>>, 
                            std::greater<std::tuple<int, int, int>>> pq;

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int max_time = 0;

        while (!pq.empty()) {
            auto [elevation, r, c] = pq.top();
            pq.pop();

            max_time = std::max(max_time, elevation);

            if (r == n - 1 && c == n - 1) {
                return max_time;
            }

            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }

        return max_time;
    }
};