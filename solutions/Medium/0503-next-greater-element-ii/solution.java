// ──────────────────────────────────────────────────
// Problem  : 503. Next Greater Element II
// Difficulty: Medium
// Tags     : Array, Stack, Monotonic Stack
// Link     : https://leetcode.com/problems/next-greater-element-ii/
// Runtime  : 15 ms (beats 57%)
// Memory   : 48932000 (beats 7%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

/*class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer> st= new Stack<>();
        int[] arr= new int[nums.length];
            for(int i= 2*nums.length-1;i>=0;i--){
            int curr=nums[i%nums.length];
            while(!st.isEmpty() && st.peek()<=curr){
                st.pop();
            }
            if(i<nums.length){// this line is imp cuz inga erundhu than value store panna aarampikurom andha duplicate edathula erundha pannama epo length kula varutho andha index apola erundhu store panna start pannudhu
            if(st.isEmpty()){
                arr[i]= -1;
            }else{
                arr[i]= st.peek();
            }}
            st.push(curr);
        }
        return arr;
        
    }
}*/
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer>st = new Stack<>();
        int[] arr= new int[nums.length];
        for(int i=2*nums.length-1;i>=0;i--){
            int curr=nums[i%nums.length];
            while(!st.isEmpty() && curr>=st.peek()){
                st.pop();
            }
            if(i<nums.length){
                if(st.isEmpty()){
                    arr[i]=-1;
                }else{
                    arr[i]=st.peek();
                }
            }
            st.push(curr);
        }
        return arr;
    }
}