# ──────────────────────────────────────────────────
# Problem  : 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
# Difficulty: Easy
# Tags     : Array
# Link     : https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
# Runtime  : 0 ms (beats 100%)
# Memory   : 19068000 (beats 94%)
# Language : python3
# Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
# Synced by: leetie
# ──────────────────────────────────────────────────

class Solution:
    def longestMonotonicSubarray(self, nums: list[int]) -> int:
        best = up = down = 1
        for a, b in pairwise(nums):
            up = up + 1 if a < b else 1  # increasing streak ending at b
            down = down + 1 if a > b else 1  # decreasing streak ending at b
            best = max(best, up, down)
        return best