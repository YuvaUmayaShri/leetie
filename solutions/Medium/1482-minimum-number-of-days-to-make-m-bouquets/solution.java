// ──────────────────────────────────────────────────
// Problem  : 1482. Minimum Number of Days to Make m Bouquets
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Runtime  : 19 ms (beats 38%)
// Memory   : 82564000 (beats 67%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int possible(int[] bloomDay,int day,int k){
        int count=0;
        int bou=0;
        for(int i=0;i<bloomDay.length;i++){
            if(bloomDay[i]<=day){
                count++;
                if (count ==k){
                    bou++;
                    count=0;
                }
            }else{
                count=0;
            }

        }
        return bou;
    }
    public int minDays(int[] bloomDay, int m, int k) {
        if ((long)m * k > bloomDay.length) {
            return -1;   //edge case
        }
        int min=Integer.MAX_VALUE;
        int max=0;
        for(int i=0;i<bloomDay.length;i++){
            min=Math.min(min,bloomDay[i]);
            max=Math.max(max,bloomDay[i]);
        }
        int low=min;
        int high=max;
        int day=0;
        int bou=0;
        while(low<=high){
            day=(low+high)/2;
        
        bou=possible(bloomDay,day,k);
        if(bou<m){
            low=day+1;
        }else{
            high=day-1;
        }
        }
        
       return low;
            

        
        
    }
}