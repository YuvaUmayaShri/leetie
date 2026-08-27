// ──────────────────────────────────────────────────
// Problem  : 1011. Capacity To Ship Packages Within D Days
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Runtime  : 11 ms (beats 65%)
// Memory   : 49984000 (beats 88%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int travel(int capacity,int[] weights){
        int count=1;//First day already start aagirukku, so day count 1 la start pannanum.inga else part la epo new day start aagutho athula erundhu than count edukuthu but andha first day kanakula ila so start with 1
        int tot=0;
        for(int i=0;i<weights.length;i++){
            if(tot +weights[i]<=capacity){
                tot+=weights[i];
            }else {
                count++;
                tot =weights[i];
            }
        }
        return count;

    }
    public int shipWithinDays(int[] weights, int days) {
        int low= 0;
        int sum=0;
        int count;
        for(int i=0;i<weights.length;i++){
            low=Math.max(low,weights[i]);
            sum+=weights[i];
        }
        int high= sum;
        int capacity;
        while(low<=high){
            capacity=(low+high)/2;
            count=travel(capacity,weights);
            if(count<=days){
                high=capacity-1;;
            }else{
                low= capacity+1;
            }
        }
        return low;//Binary search mudinjadhum low dhaan minimum possible (valid) capacity, so low return pannuvom.
        
        
    }
}