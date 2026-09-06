// ──────────────────────────────────────────────────
// Problem  : 480. Sliding Window Median
// Difficulty: Hard
// Tags     : Array, Hash Table, Sliding Window, Heap (Priority Queue), Treap
// Link     : https://leetcode.com/problems/sliding-window-median/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8724000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int compare(const void* a, const void* b) {
    long long diff = (long long)(*(int*)a) - (long long)(*(int*)b);
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

void insert(int* sorted, int* size, int val) {
    int left = 0, right = *size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sorted[mid] < val) left = mid + 1;
        else right = mid - 1;
    }
    for (int i = *size; i > left; i--) {
        sorted[i] = sorted[i - 1];
    }
    sorted[left] = val;
    (*size)++;
}

void removeVal(int* sorted, int* size, int val) {
    int left = 0, right = *size - 1, idx = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sorted[mid] == val) {
            idx = mid;
            break;
        } else if (sorted[mid] < val) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    for (int i = idx; i < *size - 1; i++) {
        sorted[i] = sorted[i + 1];
    }
    (*size)--;
}

double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int count = numsSize - k + 1;
    double* result = (double*)malloc(count * sizeof(double));
    int* sorted = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        sorted[i] = nums[i];
    }

    qsort(sorted, k, sizeof(int), compare);

    int windowSize = k;

    for (int i = 0; i < count; i++) {
        if (k % 2 == 1) {
            result[i] = (double)sorted[k / 2];
        } else {
            result[i] = ((double)sorted[k / 2 - 1] + (double)sorted[k / 2]) / 2.0;
        }

        if (i < count - 1) {
            removeVal(sorted, &windowSize, nums[i]);
            insert(sorted, &windowSize, nums[i + k]);
        }
    }

    free(sorted);
    *returnSize = count;
    return result;
}