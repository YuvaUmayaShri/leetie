# ──────────────────────────────────────────────────
# Problem  : 3789. Minimum Cost to Acquire Required Items
# Difficulty: Medium
# Tags     : Math, Greedy
# Link     : https://leetcode.com/problems/minimum-cost-to-acquire-required-items/
# Runtime  : 1 ms (beats 38%)
# Memory   : 19300000 (beats 66%)
# Language : python3
# Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
# Synced by: leetie
# ──────────────────────────────────────────────────

class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        c1, c2, cb = cost1, cost2, costBoth
        n1, n2 = need1, need2
        pairs = min(n1, n2)
        cost_pairs = pairs * min(cb, c1 + c2)
        rem1 = n1 - pairs
        rem2 = n2 - pairs
        cost_rem = rem1 * min(c1, cb) + rem2 * min(c2, cb)
        return cost_pairs + cost_rem