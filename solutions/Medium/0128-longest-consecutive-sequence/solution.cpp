// ──────────────────────────────────────────────────
// Problem  : 128. Longest Consecutive Sequence
// Difficulty: Medium
// Tags     : Array, Hash Table, Union-Find
// Link     : https://leetcode.com/problems/longest-consecutive-sequence/
// Runtime  : 96 ms (beats 19%)
// Memory   : 88712000 (beats 77%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    //Approach : Hashing using unordered_set

    //Time Complexity = O(n) =>
    /* Inserting elements into unordered_set → O(n).
    * Traversing unique elements → O(n).
    * All while loops combined → O(n), since each consecutive sequence is traversed only once.
    * Total: O(n).
    */

    //Space Complexity = O(1) =>
    /* unordered_set stores at most n unique elements → O(n).
    * Additional variables → O(1).
    * Total: O(n).
    */

    int longestConsecutive(vector<int>& nums) {
        
        //1.)
        unordered_set<int> st(nums.begin(), nums.end());
        //2.)
        int longest = 0;//to store the count of longest consecutive sequence

        //3.) traverse each unique element in set
        for(int num : st){

            //4.)check whether num-1 exists in set
            if(num == INT_MIN || !st.count(num - 1)){//not present in the set
                
                //5.)
                int currNum = num;
                int count = 1; //starting point of sequence found

                //6.)if currNum+1 exists means increment sequence length
                while(currNum != INT_MAX && st.count(currNum + 1)){
                    
                    currNum++;
                    count++;
                }

                //7.) Update longest
                longest = max(longest, count);

            }            
        }
        
        //8.) finally return the output
        return longest;
        
    }
};