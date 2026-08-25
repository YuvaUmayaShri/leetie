// ──────────────────────────────────────────────────
// Problem  : 1283. Find the Smallest Divisor Given a Threshold
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Runtime  : 6 ms (beats 99%)
// Memory   : 50960000 (beats 74%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
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
            int sum=0;
            for(int i=0;i<nums.length;i++){
                sum+=(nums[i]+mid-1)/mid;
            }
            if(sum <= threshold){
                ans= mid;
                high=mid-1;
            }else{
                low= mid+1;
            }

        }
        return ans;
        
    }
}