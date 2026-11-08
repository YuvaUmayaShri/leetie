# ──────────────────────────────────────────────────
# Problem  : 1267. Count Servers that Communicate
# Difficulty: Medium
# Tags     : Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix, Counting
# Link     : https://leetcode.com/problems/count-servers-that-communicate/
# Runtime  : 12 ms (beats 88%)
# Memory   : 21360000 (beats 90%)
# Language : python3
# Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
# Synced by: leetie
# ──────────────────────────────────────────────────

class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        rows = [sum(row) for row in grid]  
        cols = [sum(col) for col in zip(*grid)]  

        ans = 0
        for i, row in enumerate(grid):
            for j, server in enumerate(row):
                if server and rows[i] + cols[j] > 2:  
                    ans += 1
        return ans