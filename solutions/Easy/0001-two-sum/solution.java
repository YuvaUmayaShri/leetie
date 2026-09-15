// ──────────────────────────────────────────────────
// Problem  : 1. Two Sum
// Difficulty: Easy
// Tags     : Array, Hash Table
// Link     : https://leetcode.com/problems/two-sum/
// Runtime  : 0 ms (beats 0%)
// Memory   : 42744000 (beats 0%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] arr= new int[2];
        int l=0;
        int r=1;
        int sum=0;
        for(int i=0;i<nums.length;i++){
            if(nums[l]+nums[r]==target){
                arr[0]=l;
                arr[1]=r;
                break;
            }else{
                l++;
                r++;
            }
        }
        return arr;
    }
}