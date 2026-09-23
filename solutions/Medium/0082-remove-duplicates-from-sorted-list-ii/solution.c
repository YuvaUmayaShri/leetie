// ──────────────────────────────────────────────────
// Problem  : 82. Remove Duplicates from Sorted List II
// Difficulty: Medium
// Tags     : Linked List, Two Pointers
// Link     : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 11420000 (beats 64%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (head) {
        if (head->next && head->val == head->next->val) {
            while (head->next && head->val == head->next->val) {
                head = head->next;
            }
            prev->next = head->next;
        } else {
            prev = prev->next;
        }
        head = head->next;
    }

    return dummy.next;
}