// ──────────────────────────────────────────────────
// Problem  : 1901. Find a Peak Element II
// Difficulty: Medium
// Tags     : Array, Binary Search, Matrix
// Link     : https://leetcode.com/problems/find-a-peak-element-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 119316000 (beats 21%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int maximum(int[][] mat,int mid,int n){
        int max=-1;
        int index=-1;
        for(int i=0;i<n;i++){
            if(mat[i][mid] >max){
                max=mat[i][mid];
                index=i;
            }

        }
        return index;
    }
    public int[] findPeakGrid(int[][] mat) {
        int n=mat.length;
        int m=mat[0].length;
        int low=0;
        int high=m-1;
        int mid;
        int[] ans= new int[2];
        while(low<=high){
            mid=(low+high)/2;
            int row=maximum(mat,mid,n);
            int left=mid-1>=0 ? mat[row][mid-1]:-1;
            int right=mid+1<m?mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                ans[0]=row;
                ans[1]=mid;
                return ans;

            }
            if(mat[row][mid] <left){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
        
    }
}