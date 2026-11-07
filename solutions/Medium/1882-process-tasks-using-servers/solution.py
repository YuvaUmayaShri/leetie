# ──────────────────────────────────────────────────
# Problem  : 1882. Process Tasks Using Servers
# Difficulty: Medium
# Tags     : Array, Heap (Priority Queue)
# Link     : https://leetcode.com/problems/process-tasks-using-servers/
# Runtime  : 646 ms (beats 34%)
# Memory   : 66648000 (beats 18%)
# Language : python3
# Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
# Synced by: leetie
# ──────────────────────────────────────────────────

class Solution:
    def assignTasks(self, servers: list[int], tasks: list[int]) -> list[int]:
        free = [(w, i) for i, w in enumerate(servers)]
        heapify(free)

        ans, busy = [], []  # busy: (second it frees up, weight, index)
        for s, t in enumerate(tasks):
            while busy and busy[0][0] <= s:  # done by second s
                heappush(free, heappop(busy)[1:])
            start, w, i = (s, *heappop(free)) if free else heappop(busy)  # none free: the first to finish takes it
            heappush(busy, (start + t, w, i))
            ans.append(i)

        return ans