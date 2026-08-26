// ──────────────────────────────────────────────────
// Problem  : 539. Minimum Time Difference
// Difficulty: Medium
// Tags     : Array, Math, String, Sorting
// Link     : https://leetcode.com/problems/minimum-time-difference/
// Runtime  : 3 ms (beats 90%)
// Memory   : 47564000 (beats 87%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

import java.util.List;
import java.util.Collections;

class Solution {
    public int findMinDifference(List<String> timePoints) {
        boolean[] minutes = new boolean[1440];
        
        for (String time : timePoints) {
            String[] parts = time.split(":");
            int h = Integer.parseInt(parts[0]);
            int m = Integer.parseInt(parts[1]);
            int totalMinutes = h * 60 + m;
            
            if (minutes[totalMinutes]) {
                return 0;
            }
            minutes[totalMinutes] = true;
        }

        int minDiff = Integer.MAX_VALUE;
        int prev = -1;
        int first = -1;
        int last = -1;

        for (int i = 0; i < 1440; i++) {
            if (minutes[i]) {
                if (first == -1) {
                    first = i;
                }
                if (prev != -1) {
                    minDiff = Math.min(minDiff, i - prev);
                }
                prev = i;
                last = i;
            }
        }

        minDiff = Math.min(minDiff, 1440 - last + first);
        return minDiff;
    }
}