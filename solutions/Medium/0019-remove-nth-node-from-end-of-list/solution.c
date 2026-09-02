// ──────────────────────────────────────────────────
// Problem  : 19. Remove Nth Node From End of List
// Difficulty: Medium
// Tags     : Linked List, Two Pointers
// Link     : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8604000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);

    return dummy.next;
}