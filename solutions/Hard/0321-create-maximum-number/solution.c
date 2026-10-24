// ──────────────────────────────────────────────────
// Problem  : 321. Create Maximum Number
// Difficulty: Hard
// Tags     : Array, Two Pointers, Stack, Greedy, Monotonic Stack
// Link     : https://leetcode.com/problems/create-maximum-number/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8348000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    *returnSize = k;
    int* best = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) best[i] = 0;

    int* sub1 = (int*)malloc(k * sizeof(int));
    int* sub2 = (int*)malloc(k * sizeof(int));
    int* merged = (int*)malloc(k * sizeof(int));

    int start = k - nums2Size > 0 ? k - nums2Size : 0;
    int end = k < nums1Size ? k : nums1Size;

    for (int i = start; i <= end; i++) {
        int len1 = i;
        int len2 = k - i;

        int top1 = -1;
        for (int j = 0; j < nums1Size; j++) {
            while (top1 >= 0 && sub1[top1] < nums1[j] && nums1Size - j > len1 - top1 - 1) {
                top1--;
            }
            if (top1 + 1 < len1) {
                sub1[++top1] = nums1[j];
            }
        }

        int top2 = -1;
        for (int j = 0; j < nums2Size; j++) {
            while (top2 >= 0 && sub2[top2] < nums2[j] && nums2Size - j > len2 - top2 - 1) {
                top2--;
            }
            if (top2 + 1 < len2) {
                sub2[++top2] = nums2[j];
            }
        }

        int p1 = 0, p2 = 0, mIdx = 0;
        while (p1 < len1 || p2 < len2) {
            int* a = sub1 + p1;
            int* b = sub2 + p2;
            int rem1 = len1 - p1;
            int rem2 = len2 - p2;
            
            int useFirst = 0;
            if (p2 >= len2) {
                useFirst = 1;
            } else if (p1 >= len1) {
                useFirst = 0;
            } else {
                int cmp = 0;
                int x = p1, y = p2;
                while (x < len1 && y < len2) {
                    if (sub1[x] != sub2[y]) {
                        cmp = sub1[x] - sub2[y];
                        break;
                    }
                    x++;
                    y++;
                }
                if (cmp == 0) {
                    cmp = (len1 - x) - (len2 - y);
                }
                useFirst = (cmp >= 0);
            }

            if (useFirst) {
                merged[mIdx++] = sub1[p1++];
            } else {
                merged[mIdx++] = sub2[p2++];
            }
        }

        int isGreater = 0;
        for (int j = 0; j < k; j++) {
            if (merged[j] > best[j]) {
                isGreater = 1;
                break;
            } else if (merged[j] < best[j]) {
                break;
            }
        }

        if (isGreater) {
            for (int j = 0; j < k; j++) {
                best[j] = merged[j];
            }
        }
    }

    free(sub1);
    free(sub2);
    free(merged);

    return best;
}