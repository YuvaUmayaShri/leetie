// ──────────────────────────────────────────────────
// Problem  : 480. Sliding Window Median
// Difficulty: Hard
// Tags     : Array, Hash Table, Sliding Window, Heap (Priority Queue), Treap
// Link     : https://leetcode.com/problems/sliding-window-median/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8412000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int compare(const void* a, const void* b) {
    double diff = *(double*)a - *(double*)b;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int count = numsSize - k + 1;
    double* result = (double*)malloc(count * sizeof(double));
    double* window = (double*)malloc(k * sizeof(double));

    for (int i = 0; i < k; i++) {
        window[i] = (double)nums[i];
    }

    qsort(window, k, sizeof(double), compare);

    for (int i = 0; i < count; i++) {
        if (k % 2 == 1) {
            result[i] = window[k / 2];
        } else {
            result[i] = (window[k / 2 - 1] + window[k / 2]) / 2.0;
        }

        if (i < count - 1) {
            double outgoing = (double)nums[i];
            double incoming = (double)nums[i + k];

            int idx = 0;
            while (idx < k && window[idx] != outgoing) {
                idx++;
            }

            while (idx < k - 1 && window[idx + 1] < incoming) {
                window[idx] = window[idx + 1];
                idx++;
            }
            while (idx > 0 && window[idx - 1] > incoming) {
                window[idx] = window[idx - 1];
                idx--;
            }

            window[idx] = incoming;
        }
    }

    free(window);
    *returnSize = count;
    return result;
}