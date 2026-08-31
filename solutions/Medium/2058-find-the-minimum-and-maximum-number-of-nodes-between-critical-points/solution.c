// ──────────────────────────────────────────────────
// Problem  : 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// Difficulty: Medium
// Tags     : Linked List
// Link     : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
// Runtime  : 0 ms (beats 100%)
// Memory   : 49032000 (beats 77%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <limits.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;

    if (!head || !head->next || !head->next->next) {
        return result;
    }

    struct ListNode* prev = head;
    struct ListNode* curr = head->next;
    
    int index = 1;
    int first_critical = -1;
    int prev_critical = -1;
    int min_dist = INT_MAX;

    while (curr->next != NULL) {
        struct ListNode* next = curr->next;
        
        if ((curr->val > prev->val && curr->val > next->val) || 
            (curr->val < prev->val && curr->val < next->val)) {
            
            if (first_critical == -1) {
                first_critical = index;
            } else {
                min_dist = (index - prev_critical < min_dist) ? (index - prev_critical) : min_dist;
            }
            prev_critical = index;
        }

        prev = curr;
        curr = next;
        index++;
    }

    if (first_critical == -1 || first_critical == prev_critical) {
        return result;
    }

    result[0] = min_dist;
    result[1] = prev_critical - first_critical;

    return result;
}