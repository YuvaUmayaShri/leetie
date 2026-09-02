// ──────────────────────────────────────────────────
// Problem  : 141. Linked List Cycle
// Difficulty: Easy
// Tags     : Hash Table, Linked List, Two Pointers, Floyd's Cycle Finding Algorithm
// Link     : https://leetcode.com/problems/linked-list-cycle/
// Runtime  : 7 ms (beats 92%)
// Memory   : 12012000 (beats 7%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}