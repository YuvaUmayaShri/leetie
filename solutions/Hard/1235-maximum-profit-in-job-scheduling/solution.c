// ──────────────────────────────────────────────────
// Problem  : 1235. Maximum Profit in Job Scheduling
// Difficulty: Hard
// Tags     : Array, Binary Search, Dynamic Programming, Sorting
// Link     : https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Runtime  : 30 ms (beats 33%)
// Memory   : 19744000 (beats 17%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

typedef struct {
    int startTime;
    int endTime;
    int profit;
} Job;

int compare(const void* a, const void* b) {
    return ((Job*)a)->endTime - ((Job*)b)->endTime;
}

int binarySearch(Job* jobs, int index) {
    int low = 0, high = index - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (jobs[mid].endTime <= jobs[index].startTime) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize) {
    int n = startTimeSize;
    Job* jobs = (Job*)malloc(n * sizeof(Job));

    for (int i = 0; i < n; i++) {
        jobs[i].startTime = startTime[i];
        jobs[i].endTime = endTime[i];
        jobs[i].profit = profit[i];
    }

    qsort(jobs, n, sizeof(Job), compare);

    int* dp = (int*)malloc(n * sizeof(int));
    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; i++) {
        int currentProfit = jobs[i].profit;
        int prevIdx = binarySearch(jobs, i);
        
        if (prevIdx != -1) {
            currentProfit += dp[prevIdx];
        }

        dp[i] = currentProfit > dp[i - 1] ? currentProfit : dp[i - 1];
    }

    int result = dp[n - 1];

    free(jobs);
    free(dp);

    return result;
}