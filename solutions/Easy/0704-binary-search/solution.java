// ──────────────────────────────────────────────────
// Problem  : 704. Binary Search
// Difficulty: Easy
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/binary-search/
// Runtime  : 0 ms (beats 100%)
// Memory   : 48332000 (beats 50%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

/*class Solution {
    public int search(int[] nums, int target) {
        int n=nums.length;
        int low=0;
        int high =n-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid] > target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
       
        return -1;
       
      
    }
}*/
class Solution {
    public int search(int[] nums, int target) {
        int low=0;
        int high =nums.length -1;
        int mid;
        int index=-1;
        while(low<= high){
            mid=(low+high)/2;
            if(nums[mid] ==target){
                index=mid;
                return index;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return index;

    }
}