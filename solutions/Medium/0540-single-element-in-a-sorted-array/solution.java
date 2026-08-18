// ──────────────────────────────────────────────────
// Problem  : 540. Single Element in a Sorted Array
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/single-element-in-a-sorted-array/
// Runtime  : 0 ms (beats 100%)
// Memory   : 52640000 (beats 91%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int singleNonDuplicate(int[] nums) {
            int n= nums.length;
            int low=1;
            int ans=0;
            int high =n-2;
        
            if(n==1){
                return nums[0];
            }
            if(nums[0]!=nums[1]){
                return nums[0];
            }
            if(nums[n-1]!=nums[n-2]){
                return nums[n-1];
                
            }
           
           
            int mid;
            while(low<=high){
                                               
            mid=(low+high)/2;
            if(nums[mid]!=nums[mid-1]&& nums[mid]!=nums[mid+1]){
                ans=nums[mid];
                break;
            }
            if(mid%2==1 && nums[mid]==nums[mid-1]||mid%2==0 && nums[mid]==nums[mid+1]){//checking where the mid is standing(whether left)if this condition satisfies then mid is in left and the element in right ,so move mid...if this condition fails then then mid is in right and the element is in left so eliminate right
                low=mid+1;  
            }else{
                high=mid-1;
            }
            }
        return ans;
    }
}