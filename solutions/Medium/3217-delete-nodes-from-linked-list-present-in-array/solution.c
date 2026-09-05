// ──────────────────────────────────────────────────
// Problem  : 3217. Delete Nodes From Linked List Present in Array
// Difficulty: Medium
// Tags     : Array, Hash Table, Linked List
// Link     : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
// Runtime  : 3 ms (beats 95%)
// Memory   : 62668000 (beats 75%)
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

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    bool present[100001] = {false};
    for (int i = 0; i < numsSize; i++) {
        present[nums[i]] = true;
    }

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;

    while (curr != NULL) {
        if (present[curr->val]) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }

    return dummy.next;
}