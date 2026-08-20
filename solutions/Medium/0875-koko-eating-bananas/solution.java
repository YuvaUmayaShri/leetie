// ──────────────────────────────────────────────────
// Problem  : 875. Koko Eating Bananas
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/koko-eating-bananas/
// Runtime  : 0 ms (beats 0%)
// Memory   : 42112000 (beats 0%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int low=1;
        int max=0;
        int mid;
        int high=0;
        for(int i=0;i<h;i++){
            high=Math.max(max,i);
        }
        while(low<=high){
            mid=(low+high)/2;
            long tot=0;
            for(int i=0;i<piles.length;i++){
                tot+=(long)Math.ceil((double)piles[i]/mid);
            }
            if(tot<=h){
                low=mid+1;
            }else{
                high=mid-1;
            }       
        } 
        return low;
    }      
}