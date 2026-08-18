// ──────────────────────────────────────────────────
// Problem  : 4. Median of Two Sorted Arrays
// Difficulty: Hard
// Tags     : Array, Binary Search, Divide and Conquer
// Link     : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Runtime  : 3 ms (beats 0%)
// Memory   : 45792000 (beats 0%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int result[] = new int[nums1.length + nums2.length];
        for(int i =0;i<nums1.length;i++){
            result[i]= nums1[i];
        }
        for(int j =0;j<nums2.length;j++){
            result[nums1.length+
            j] =nums2[j];
        }
        for(int j =0;j<result.length;j++){
           System.out.print(result[j] +" ");
        }
        Arrays.sort(result);
        int x = result.length;
        if(x%2 !=0) return((float)result[x/2]);
        else return((float)((result[x/2-1] +result[x/2])/2.0));
    }
}