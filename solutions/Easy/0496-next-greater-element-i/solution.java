// ──────────────────────────────────────────────────
// Problem  : 496. Next Greater Element I
// Difficulty: Easy
// Tags     : Array, Hash Table, Stack, Monotonic Stack
// Link     : https://leetcode.com/problems/next-greater-element-i/
// Runtime  : 4 ms (beats 74%)
// Memory   : 45212000 (beats 50%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

/*class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> st = new Stack<>();
        HashMap<Integer,Integer> map= new HashMap<>();
        for(int i=nums2.length-1;i>=0;i--){
            int curr=nums2[i];
            while(!st.isEmpty() && st.peek() < curr){
                st.pop();
            }
            if(st.isEmpty()){
                map.put(curr,-1);
            }else{
                map.put(curr,st.peek());
            }
            st.push(curr);
        }
        int arr[]  = new int [nums1.length];
        for(int i=0;i<nums1.length;i++){
            arr[i] = map.get(nums1[i]);
        }
        return arr;
    }
}*/
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> st = new Stack<>();
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i=nums2.length-1;i>=0;i--){
            int curr=nums2[i];
            while(!st.isEmpty() && curr>st.peek()){
                st.pop();
            }
            if(st.isEmpty()){
                map.put(curr,-1);
            }else{
                map.put(curr,st.peek());
            }
            st.push(curr);
        }
        int[] arr=new int[nums1.length];
        for(int i=0;i<nums1.length;i++){
            arr[i]=map.get(nums1[i]);
        }
        return arr;
    }
}
