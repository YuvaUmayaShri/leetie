// ──────────────────────────────────────────────────
// Problem  : 24. Swap Nodes in Pairs
// Difficulty: Medium
// Tags     : Linked List, Recursion
// Link     : https://leetcode.com/problems/swap-nodes-in-pairs/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8636000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (prev->next != NULL && prev->next->next != NULL) {
        struct ListNode* first = prev->next;
        struct ListNode* second = prev->next->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }

    return dummy.next;
}