// ──────────────────────────────────────────────────
// Problem  : 826. Most Profit Assigning Work
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search, Greedy, Sorting
// Link     : https://leetcode.com/problems/most-profit-assigning-work/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8504000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct {
    int difficulty;
    int profit;
} Job;

int compareJobs(const void* a, const void* b) {
    return ((Job*)a)->difficulty - ((Job*)b)->difficulty;
}

int compareWorkers(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    Job jobs[difficultySize];
    for (int i = 0; i < difficultySize; i++) {
        jobs[i].difficulty = difficulty[i];
        jobs[i].profit = profit[i];
    }

    qsort(jobs, difficultySize, sizeof(Job), compareJobs);
    qsort(worker, workerSize, sizeof(int), compareWorkers);

    int totalProfit = 0;
    int maxProfit = 0;
    int jobIdx = 0;

    for (int i = 0; i < workerSize; i++) {
        while (jobIdx < difficultySize && worker[i] >= jobs[jobIdx].difficulty) {
            if (jobs[jobIdx].profit > maxProfit) {
                maxProfit = jobs[jobIdx].profit;
            }
            jobIdx++;
        }
        totalProfit += maxProfit;
    }

    return totalProfit;
}