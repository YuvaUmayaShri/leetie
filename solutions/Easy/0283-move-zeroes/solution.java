// ──────────────────────────────────────────────────
// Problem  : 283. Move Zeroes
// Difficulty: Easy
// Tags     : Array, Two Pointers
// Link     : https://leetcode.com/problems/move-zeroes/
// Runtime  : 2 ms (beats 92%)
// Memory   : 48076000 (beats 7%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public void moveZeroes(int[] nums) {
        int k=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=0){
                nums[k]=nums[i];
                if(i!=k){
                    nums[i]=0;
                }
               k++;  
            }
           
            
        }
        
    }
}