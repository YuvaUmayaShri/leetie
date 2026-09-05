// ──────────────────────────────────────────────────
// Problem  : 2130. Maximum Twin Sum of a Linked List
// Difficulty: Medium
// Tags     : Linked List, Two Pointers, Stack
// Link     : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
// Runtime  : 2 ms (beats 56%)
// Memory   : 51032000 (beats 76%)
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

int pairSum(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    struct ListNode* prev = NULL;
    struct ListNode* curr = slow;
    struct ListNode* nextNode = NULL;
    
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    int maxSum = 0;
    struct ListNode* first = head;
    struct ListNode* second = prev;
    
    while (second != NULL) {
        int sum = first->val + second->val;
        if (sum > maxSum) {
            maxSum = sum;
        }
        first = first->next;
        second = second->next;
    }
    
    return maxSum;
}