// ──────────────────────────────────────────────────
// Problem  : 493. Reverse Pairs
// Difficulty: Hard
// Tags     : Array, Binary Search, Divide and Conquer, Binary Indexed Tree, Segment Tree, Merge Sort, Ordered Set, Treap
// Link     : https://leetcode.com/problems/reverse-pairs/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8428000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int reversePairs(int* nums, int numsSize) {
    int merge(int* nums, int left, int mid, int right, int* temp) {
        int count = 0;
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        int i = left, k = left, l = mid + 1;
        while (i <= mid && l <= right) {
            if (nums[i] <= nums[l]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[l++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (l <= right) {
            temp[k++] = nums[l++];
        }
        for (i = left; i <= right; i++) {
            nums[i] = temp[i];
        }

        return count;
    }

    int mergeSort(int* nums, int left, int right, int* temp) {
        if (left >= right) {
            return 0;
        }
        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid, temp) + mergeSort(nums, mid + 1, right, temp);
        count += merge(nums, left, mid, right, temp);
        return count;
    }

    int* temp = (int*)malloc(numsSize * sizeof(int));
    int result = mergeSort(nums, 0, numsSize - 1, temp);
    free(temp);
    return result;
}