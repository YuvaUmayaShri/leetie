// ──────────────────────────────────────────────────
// Problem  : 162. Find Peak Element
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/find-peak-element/
// Runtime  : N/A (beats 0%)
// Memory   : N/A (beats 0%)
// Language : java
// Copyright: (c) 2026 Shreeprasandh K. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────


class Solution{
    public int findPeakElement(int[] nums){
        int n= nums.length;
        int low =1;
        int high=n-2;
        int mid;
        if(n==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
            
        }
        if(nums[n-1] >nums[n-2]){
            return n-1;
        
        }
        int ans=0;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid] >nums[mid+1] && nums[mid] >nums[mid+1]){
                ans=mid;
            }
            if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
}