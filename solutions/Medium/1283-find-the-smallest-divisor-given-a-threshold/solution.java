// ──────────────────────────────────────────────────
// Problem  : 1283. Find the Smallest Divisor Given a Threshold
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Runtime  : 7 ms (beats 83%)
// Memory   : 51156000 (beats 35%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public boolean possible(int[] nums,int threshold,int mid){
        int sum=0;
        for(int i=0;i<nums.length;i++){
            sum+=(nums[i]+mid-1)/mid;
        }
        if(sum <= threshold){
            return true;
            
        }else{
            return false;
        }

    }
    public int smallestDivisor(int[] nums, int threshold) {
        
        int[] arr = new int[10];
        int low=1;
        int high=0;
        for(int num:nums){
            high=Math.max(high,num);
        }
        int mid;
        int ans=high;
        while(low<=high){
            mid=(low+high)/2;
            if(possible( nums,threshold, mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
        
    }
}