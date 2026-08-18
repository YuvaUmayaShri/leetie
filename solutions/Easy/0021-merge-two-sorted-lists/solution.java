// ──────────────────────────────────────────────────
// Problem  : 21. Merge Two Sorted Lists
// Difficulty: Easy
// Tags     : Linked List, Recursion
// Link     : https://leetcode.com/problems/merge-two-sorted-lists/
// Runtime  : 0 ms (beats 100%)
// Memory   : 44140000 (beats 76%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(0);
        ListNode temp = dummy;

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                temp.next = list1;
                list1 = list1.next;
            } else {
                temp.next = list2;
                list2 = list2.next;
            }
            temp = temp.next;
        }

        if (list1 != null) temp.next = list1;
        else temp.next = list2;

        return dummy.next;
    }
}
