// ──────────────────────────────────────────────────
// Problem  : 1721. Swapping Nodes in a Linked List
// Difficulty: Medium
// Tags     : Linked List, Two Pointers
// Link     : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Runtime  : 0 ms (beats 100%)
// Memory   : 53392000 (beats 98%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* left = head;
    struct ListNode* right = head;
    struct ListNode* curr = head;

    for (int i = 1; i < k; i++) {
        left = left->next;
    }

    curr = left;
    while (curr->next != NULL) {
        curr = curr->next;
        right = right->next;
    }

    int temp = left->val;
    left->val = right->val;
    right->val = temp;

    return head;
}