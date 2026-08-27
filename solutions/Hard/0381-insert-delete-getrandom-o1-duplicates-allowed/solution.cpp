// ──────────────────────────────────────────────────
// Problem  : 381. Insert Delete GetRandom O(1) - Duplicates allowed
// Difficulty: Hard
// Tags     : Array, Hash Table, Math, Design, Randomized
// Link     : https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
// Runtime  : 0 ms (beats 0%)
// Memory   : 9076000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>

class RandomizedCollection {
private:
    std::vector<int> nums;
    std::unordered_map<int, std::unordered_set<int>> idxMap;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool not_present = idxMap[val].empty();
        idxMap[val].insert(nums.size());
        nums.push_back(val);
        return not_present;
    }

    bool remove(int val) {
        if (idxMap[val].empty()) return false;

        int remove_idx = *idxMap[val].begin();
        idxMap[val].erase(remove_idx);

        int last_val = nums.back();
        if (remove_idx != nums.size() - 1) {
            nums[remove_idx] = last_val;
            idxMap[last_val].erase(nums.size() - 1);
            idxMap[last_val].insert(remove_idx);
        }

        nums.pop_back();
        if (idxMap[val].empty()) {
            idxMap.erase(val);
        }

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};