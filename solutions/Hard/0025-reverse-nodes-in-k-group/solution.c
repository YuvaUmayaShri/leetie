// ──────────────────────────────────────────────────
// Problem  : 25. Reverse Nodes in k-Group
// Difficulty: Hard
// Tags     : Linked List, Recursion
// Link     : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12292000 (beats 46%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k == 1) {
        return head;
    }

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prevGroup = &dummy;

    while (1) {
        struct ListNode* kth = prevGroup;
        for (int i = 0; i < k && kth != NULL; i++) {
            kth = kth->next;
        }

        if (kth == NULL) {
            break;
        }

        struct ListNode* groupNext = kth->next;
        struct ListNode* curr = prevGroup->next;
        struct ListNode* prev = groupNext;

        while (curr != groupNext) {
            struct ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        struct ListNode* tmp = prevGroup->next;
        prevGroup->next = kth;
        prevGroup = tmp;
    }

    return dummy.next;
}