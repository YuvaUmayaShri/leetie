// ──────────────────────────────────────────────────
// Problem  : 731. My Calendar II
// Difficulty: Medium
// Tags     : Array, Binary Search, Design, Segment Tree, Prefix Sum, Ordered Set
// Link     : https://leetcode.com/problems/my-calendar-ii/
// Runtime  : 21 ms (beats 77%)
// Memory   : 39412000 (beats 85%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <vector>
#include <algorithm>

class MyCalendarTwo {
private:
    std::vector<std::pair<int, int>> bookings;
    std::vector<std::pair<int, int>> overlaps;

public:
    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {
        for (const auto& o : overlaps) {
            if (std::max(startTime, o.first) < std::min(endTime, o.second)) {
                return false;
            }
        }

        for (const auto& b : bookings) {
            int start = std::max(startTime, b.first);
            int end = std::min(endTime, b.second);
            if (start < end) {
                overlaps.push_back({start, end});
            }
        }

        bookings.push_back({startTime, endTime});
        return true;
    }
};