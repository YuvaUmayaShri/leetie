# ──────────────────────────────────────────────────
# Problem  : 1606. Find Servers That Handled Most Number of Requests
# Difficulty: Hard
# Tags     : Array, Heap (Priority Queue), Simulation, Ordered Set
# Link     : https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
# Runtime  : 281 ms (beats 71%)
# Memory   : 47052000 (beats 12%)
# Language : python3
# Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
# Synced by: leetie
# ──────────────────────────────────────────────────

class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        free = list(range(k))  # already a heap: each free server is keyed by its next turn

        handled, busy = [], []  # busy: (time it frees up, server)
        for i, (t, d) in enumerate(zip(arrival, load)):
            while busy and busy[0][0] <= t:  # done by time t
                heappush(free, i + (heappop(busy)[1] - i) % k)  # its first turn from i on
            if free:  # otherwise the request is dropped
                x = heappop(free) % k
                heappush(busy, (t + d, x))
                handled.append(x)

        return multimode(handled)