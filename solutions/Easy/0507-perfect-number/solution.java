// ──────────────────────────────────────────────────
// Problem  : 507. Perfect Number
// Difficulty: Easy
// Tags     : Math
// Link     : https://leetcode.com/problems/perfect-number/
// Runtime  : 1072 ms (beats 65%)
// Memory   : 42000000 (beats 80%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public boolean checkPerfectNumber(int num) {
        int div= num/2;
        int sum=0;
        for(int i=1;i<=div;i++){    
            if(num%i ==0){
                sum+=i;
            }
        }
        if(sum==num){
            return true;
        }
        return false;
    }
}