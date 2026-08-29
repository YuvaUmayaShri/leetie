// ──────────────────────────────────────────────────
// Problem  : 981. Time Based Key-Value Store
// Difficulty: Medium
// Tags     : Hash Table, String, Binary Search, Design
// Link     : https://leetcode.com/problems/time-based-key-value-store/
// Runtime  : 52 ms (beats 56%)
// Memory   : 136992000 (beats 61%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

class TimeMap {
private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store;

public:
    TimeMap() {}
    
    void set(std::string key, std::string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    std::string get(std::string key, int timestamp) {
        if (store.find(key) == store.end()) return "";
        
        const auto& values = store[key];
        int left = 0, right = values.size() - 1;
        std::string res = "";
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp) {
                res = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return res;
    }
};