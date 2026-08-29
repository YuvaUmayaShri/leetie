// ──────────────────────────────────────────────────
// Problem  : 985. Sum of Even Numbers After Queries
// Difficulty: Medium
// Tags     : Array, Simulation
// Link     : https://leetcode.com/problems/sum-of-even-numbers-after-queries/
// Runtime  : 1 ms (beats 64%)
// Memory   : 49756000 (beats 91%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <vector>

class Solution {
public:
    std::vector<int> sumEvenAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        int even_sum = 0;
        for (int x : nums) {
            if (x % 2 == 0) {
                even_sum += x;
            }
        }
        
        std::vector<int> res;
        res.reserve(queries.size());
        
        for (const auto& q : queries) {
            int val = q[0];
            int idx = q[1];
            
            if (nums[idx] % 2 == 0) {
                even_sum -= nums[idx];
            }
            
            nums[idx] += val;
            
            if (nums[idx] % 2 == 0) {
                even_sum += nums[idx];
            }
            
            res.push_back(even_sum);
        }
        
        return res;
    }
};