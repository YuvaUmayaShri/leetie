// ──────────────────────────────────────────────────
// Problem  : 15. 3Sum
// Difficulty: Medium
// Tags     : Array, Two Pointers, Sorting
// Link     : https://leetcode.com/problems/3sum/
// Runtime  : 35 ms (beats 41%)
// Memory   : 59132000 (beats 60%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0;i<nums.length-2;i++){
            if( i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int l = i+1;
            int r =nums.length-1;
            int sum=0;
            while(l<r){
                sum =nums[i]+nums[l]+nums[r];
                if(sum == 0){
                    result.add(Arrays.asList(nums[i],nums[l],nums[r]));
                    l++;
                    r--;
                
                    while(l<r && nums[l]==nums[l-1]){//to prevent duplicate triplets in final res
                        l++;
                    }
                    while(l<r  && nums[l]==nums[l-1]){
                    r--;
                    }
                }else if(sum <0){
                    l++;
                }else{
                    r--;}
            }

        }
        return result;
    }
}