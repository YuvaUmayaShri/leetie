// ──────────────────────────────────────────────────
// Problem  : 739. Daily Temperatures
// Difficulty: Medium
// Tags     : Array, Stack, Monotonic Stack
// Link     : https://leetcode.com/problems/daily-temperatures/
// Runtime  : 0 ms (beats 0%)
// Memory   : 42820000 (beats 0%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> st= new Stack<>();
        int[] nge = new int[temperatures.length];
        for(int i=temperatures.length-1;i>=0;i--){
            int curr = temperatures[i];
            while(!st.isEmpty() && temperatures[st.peek()] <=curr){
                st.pop();
            }
            if(st.isEmpty()){
                nge[i]=-1;
            }else{
                nge[i]=st.peek();
            }
            st.push(i);

        }
        int[] arr= new int[temperatures.length];
        for(int i=0;i<arr.length;i++){
            if(nge[i]== -1){
                arr[i]=0;
            }else{
                arr[i]=nge[i]-i;
            }

        }
        return arr;
    }
}