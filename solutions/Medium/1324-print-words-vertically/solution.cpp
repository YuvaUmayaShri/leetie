// ──────────────────────────────────────────────────
// Problem  : 1324. Print Words Vertically
// Difficulty: Medium
// Tags     : Array, String, Simulation
// Link     : https://leetcode.com/problems/print-words-vertically/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8736000 (beats 66%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<string> printVertically(string s) 
    {
        int mx = 0, idx;
        string word;
        vector<string>all, ans;
        stringstream sentesnce(s);
        while(sentesnce >> word)
        {
            mx = max(mx, int(word.size()));
            all.push_back(word);
        }

        map<int,string>mp;
        for(auto str:all)
        {
            idx = 0;
            for(char ch:str) mp[idx++] += ch;
            while(idx < mx) mp[idx++] += " ";
        }

        for(int i=0;i<mx;i++)
        {
            while(mp[i].back() == ' ') mp[i].pop_back();
            ans.push_back(mp[i]);
        }
        return ans;
    }
};