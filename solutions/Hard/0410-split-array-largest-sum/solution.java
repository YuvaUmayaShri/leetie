// ──────────────────────────────────────────────────
// Problem  : 410. Split Array Largest Sum
// Difficulty: Hard
// Tags     : Array, Binary Search, Dynamic Programming, Greedy, Prefix Sum
// Link     : https://leetcode.com/problems/split-array-largest-sum/
// Runtime  : 1 ms (beats 57%)
// Memory   : 42684000 (beats 97%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int possible(int[] nums,int k,int mid){
        int stud=1;
        int tot=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]+tot <=mid){
                tot+=nums[i];
            }else{
                stud++;
                tot=nums[i];
            }
        }
        return stud;
    }
    public int splitArray(int[] nums, int k) {
        int sum=0;
        int max=0;
        for(int i=0;i<nums.length;i++){
            max=Math.max(max,nums[i]);
            sum+=nums[i];
        }
        int low=max;
        int high= sum;
        int mid;
        int stud;
        while(low<=high){
            mid=(low+high)/2;
            stud=possible(nums,k,mid);
            if(stud>k){
                low=mid+1;
            }else{
                high=mid-1;
            }
            
        }
        return low;
    }
}