// ──────────────────────────────────────────────────
// Problem  : 2040. Kth Smallest Product of Two Sorted Arrays
// Difficulty: Hard
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/
// Runtime  : 768 ms (beats 22%)
// Memory   : 62764000 (beats 61%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
        long left = -10000000000L;
        long right = 10000000000L;
        long ans = right;

        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (countLessOrEqual(nums1, nums2, mid) >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }

    private long countLessOrEqual(int[] nums1, int[] nums2, long target) {
        long count = 0;

        for (int x : nums1) {
            if (x > 0) {
                int l = 0, r = nums2.length - 1;
                int pos = -1;
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    if ((long) x * nums2[m] <= target) {
                        pos = m;
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
                count += (pos + 1);
            } else if (x < 0) {
                int l = 0, r = nums2.length - 1;
                int pos = nums2.length;
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    if ((long) x * nums2[m] <= target) {
                        pos = m;
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
                count += (nums2.length - pos);
            } else {
                if (target >= 0) {
                    count += nums2.length;
                }
            }
        }

        return count;
    }
}