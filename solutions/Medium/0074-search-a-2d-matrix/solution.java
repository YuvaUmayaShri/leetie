// ──────────────────────────────────────────────────
// Problem  : 74. Search a 2D Matrix
// Difficulty: Medium
// Tags     : Array, Binary Search, Matrix
// Link     : https://leetcode.com/problems/search-a-2d-matrix/
// Runtime  : 0 ms (beats 100%)
// Memory   : 44088000 (beats 24%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n =matrix.length;
        int m=matrix[0].length;
        int low=0;
        int high =(n*m-1);
        int mid=0;
        while(low<=high){
            mid=(low+high)/2;
            if(matrix[mid/m][mid%m]==target){
                return true;
            }
            if(matrix[mid/m][mid%m]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return false;
        
    }
}