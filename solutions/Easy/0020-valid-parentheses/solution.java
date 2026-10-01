// ──────────────────────────────────────────────────
// Problem  : 20. Valid Parentheses
// Difficulty: Easy
// Tags     : String, Stack, Bracket Sequences
// Link     : https://leetcode.com/problems/valid-parentheses/
// Runtime  : 3 ms (beats 86%)
// Memory   : 43032000 (beats 85%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public boolean isValid(String s) {
        Stack<Character>  st = new Stack<>();
        for(int i=0;i <s.length();i++){
            char c=s.charAt(i);
            if(c=='('||c=='['||c=='{'){
                st.push(c);
            }else{
                if(st.isEmpty()){
                    return false;
                }else{
                    char top = st.peek();
                    if(c==')' && top=='(' ||c==']' && top=='[' ||c=='}' && top=='{' ){
                        st.pop();
                    }else{
                        return false;
                    }
                }
                
            }
        }
        return st.isEmpty();
    }
}
