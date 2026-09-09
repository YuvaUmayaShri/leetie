// ──────────────────────────────────────────────────
// Problem  : 2487. Remove Nodes From Linked List
// Difficulty: Medium
// Tags     : Linked List, Stack, Recursion, Monotonic Stack
// Link     : https://leetcode.com/problems/remove-nodes-from-linked-list/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8668000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

struct ListNode* removeNodes(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode* nextNode = removeNodes(head->next);

    if (nextNode->val > head->val) {
        return nextNode;
    }

    head->next = nextNode;
    return head;
}