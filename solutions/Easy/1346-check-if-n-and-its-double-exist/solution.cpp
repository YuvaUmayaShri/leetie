// ──────────────────────────────────────────────────
// Problem  : 1346. Check If N and Its Double Exist
// Difficulty: Easy
// Tags     : Array, Hash Table, Two Pointers, Binary Search, Sorting
// Link     : https://leetcode.com/problems/check-if-n-and-its-double-exist/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8212000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        bitset<1001> seen[2]={0};
        for(int x: arr){
            int z=abs(x);
            if ((z<=500 && seen[x<0][2*z])|| (z%2==0 && seen[x<0][z/2]))
                return 1;
            seen[x<0][z]=1;
        }
        return 0;
    }
};