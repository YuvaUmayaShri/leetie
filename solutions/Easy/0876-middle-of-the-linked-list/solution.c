// ──────────────────────────────────────────────────
// Problem  : 876. Middle of the Linked List
// Difficulty: Easy
// Tags     : Linked List, Two Pointers
// Link     : https://leetcode.com/problems/middle-of-the-linked-list/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9192000 (beats 68%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}