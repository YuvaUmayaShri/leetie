// ──────────────────────────────────────────────────
// Problem  : 1052. Grumpy Bookstore Owner
// Difficulty: Medium
// Tags     : Array, Sliding Window
// Link     : https://leetcode.com/problems/grumpy-bookstore-owner/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8620000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int totalSatisfied = 0;
    for (int i = 0; i < customersSize; i++) {
        if (grumpy[i] == 0) {
            totalSatisfied += customers[i];
        }
    }

    int currentExtra = 0;
    for (int i = 0; i < minutes; i++) {
        if (grumpy[i] == 1) {
            currentExtra += customers[i];
        }
    }

    int maxExtra = currentExtra;

    for (int i = minutes; i < customersSize; i++) {
        if (grumpy[i] == 1) {
            currentExtra += customers[i];
        }
        if (grumpy[i - minutes] == 1) {
            currentExtra -= customers[i - minutes];
        }
        if (currentExtra > maxExtra) {
            maxExtra = currentExtra;
        }
    }

    return totalSatisfied + maxExtra;
}