// ──────────────────────────────────────────────────
// Problem  : 1751. Maximum Number of Events That Can Be Attended II
// Difficulty: Hard
// Tags     : Array, Binary Search, Dynamic Programming, Sorting
// Link     : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8444000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

int compareEvents(const void* a, const void* b) {
    int* eventA = *(int**)a;
    int* eventB = *(int**)b;
    return eventA[0] - eventB[0];
}

int binarySearch(int** events, int eventsSize, int targetStart) {
    int left = 0;
    int right = eventsSize - 1;
    int ans = eventsSize;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (events[mid][0] > targetStart) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int solve(int** events, int eventsSize, int k, int idx, int count, int** dp) {
    if (idx >= eventsSize || count == k) {
        return 0;
    }

    if (dp[idx][count] != -1) {
        return dp[idx][count];
    }

    int skip = solve(events, eventsSize, k, idx + 1, count, dp);

    int nextIdx = binarySearch(events, eventsSize, events[idx][1]);
    int take = events[idx][2] + solve(events, eventsSize, k, nextIdx, count + 1, dp);

    dp[idx][count] = skip > take ? skip : take;
    return dp[idx][count];
}

int maxValue(int** events, int eventsSize, int* eventsColSize, int k) {
    qsort(events, eventsSize, sizeof(int*), compareEvents);

    int** dp = (int**)malloc(eventsSize * sizeof(int*));
    for (int i = 0; i < eventsSize; i++) {
        dp[i] = (int*)malloc((k + 1) * sizeof(int));
        for (int j = 0; j <= k; j++) {
            dp[i][j] = -1;
        }
    }

    int result = solve(events, eventsSize, k, 0, 0, dp);

    for (int i = 0; i < eventsSize; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}