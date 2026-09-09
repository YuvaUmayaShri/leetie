// ──────────────────────────────────────────────────
// Problem  : 92. Reverse Linked List II
// Difficulty: Medium
// Tags     : Linked List
// Link     : https://leetcode.com/problems/reverse-linked-list-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9544000 (beats 39%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    for (int i = 0; i < left - 1; i++) {
        prev = prev->next;
    }

    struct ListNode* curr = prev->next;

    for (int i = 0; i < right - left; i++) {
        struct ListNode* temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }

    return dummy.next;
}