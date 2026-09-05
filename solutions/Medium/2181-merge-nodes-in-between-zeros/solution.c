// ──────────────────────────────────────────────────
// Problem  : 2181. Merge Nodes in Between Zeros
// Difficulty: Medium
// Tags     : Linked List, Simulation
// Link     : https://leetcode.com/problems/merge-nodes-in-between-zeros/
// Runtime  : 0 ms (beats 100%)
// Memory   : 89328000 (beats 63%)
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

struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* modify = head->next;
    struct ListNode* traverse = head->next;

    while (traverse != NULL) {
        int sum = 0;
        while (traverse->val != 0) {
            sum += traverse->val;
            traverse = traverse->next;
        }

        modify->val = sum;
        traverse = traverse->next;
        modify->next = (traverse != NULL) ? modify->next : NULL;
        modify = modify->next;
    }

    return head->next;
}