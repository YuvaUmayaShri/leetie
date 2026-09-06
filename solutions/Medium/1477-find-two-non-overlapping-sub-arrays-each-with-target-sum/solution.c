// ──────────────────────────────────────────────────
// Problem  : 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
// Difficulty: Medium
// Tags     : Array, Hash Table, Binary Search, Dynamic Programming, Sliding Window
// Link     : https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
// Runtime  : 11 ms (beats 25%)
// Memory   : 19320000 (beats 25%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#define INF 1000000000

int minSumOfLengths(int* arr, int arrSize, int target) {
    int* min_len = (int*)malloc((arrSize + 1) * sizeof(int));
    for (int i = 0; i <= arrSize; i++) {
        min_len[i] = INF;
    }

    int left = 0;
    int current_sum = 0;
    int ans = INF;

    for (int right = 0; right < arrSize; right++) {
        current_sum += arr[right];

        while (current_sum > target) {
            current_sum -= arr[left];
            left++;
        }

        if (current_sum == target) {
            int current_len = right - left + 1;
            if (left > 0 && min_len[left] != INF) {
                if (current_len + min_len[left] < ans) {
                    ans = current_len + min_len[left];
                }
            }

            if (current_len < min_len[right + 1]) {
                min_len[right + 1] = current_len;
            }
        }

        if (min_len[right] < min_len[right + 1]) {
            min_len[right + 1] = min_len[right];
        }
    }

    free(min_len);
    return ans >= INF ? -1 : ans;
}