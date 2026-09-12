// ──────────────────────────────────────────────────
// Problem  : 3414. Maximum Score of Non-overlapping Intervals
// Difficulty: Hard
// Tags     : Array, Binary Search, Dynamic Programming, Sorting
// Link     : https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/
// Runtime  : 388 ms (beats 100%)
// Memory   : 107368000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct {
    int l, r, w, id;
} Interval;

typedef struct {
    long long weight;
    int count;
    int idx[4];
} DPState;

int compareIntervals(const void* a, const void* b) {
    Interval* i1 = (Interval*)a;
    Interval* i2 = (Interval*)b;
    if (i1->r != i2->r) return i1->r - i2->r;
    return i1->l - i2->l;
}

int compareIndices(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compareStates(DPState* a, DPState* b) {
    if (a->weight != b->weight) return a->weight > b->weight ? 1 : -1;
    int count = a->count < b->count ? a->count : b->count;
    for (int i = 0; i < count; i++) {
        if (a->idx[i] != b->idx[i]) {
            return a->idx[i] < b->idx[i] ? 1 : -1;
        }
    }
    return a->count <= b->count ? 1 : -1;
}

int* maximumWeight(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize) {
    Interval* arr = (Interval*)malloc(sizeof(Interval) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        arr[i].l = intervals[i][0];
        arr[i].r = intervals[i][1];
        arr[i].w = intervals[i][2];
        arr[i].id = i;
    }

    qsort(arr, intervalsSize, sizeof(Interval), compareIntervals);

    DPState** dp = (DPState**)malloc(sizeof(DPState*) * (intervalsSize + 1));
    for (int i = 0; i <= intervalsSize; i++) {
        dp[i] = (DPState*)calloc(5, sizeof(DPState));
    }

    for (int i = 1; i <= intervalsSize; i++) {
        int low = 0, high = i - 2, prev = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid].r < arr[i - 1].l) {
                prev = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        for (int k = 0; k <= 4; k++) {
            dp[i][k] = dp[i - 1][k];
        }

        for (int k = 1; k <= 4; k++) {
            DPState prev_state = (prev == -1) ? (DPState){0, 0, {0}} : dp[prev + 1][k - 1];
            if (prev == -1 && k > 1) continue;

            DPState cand;
            cand.weight = prev_state.weight + arr[i - 1].w;
            cand.count = prev_state.count + 1;
            for (int c = 0; c < prev_state.count; c++) {
                cand.idx[c] = prev_state.idx[c];
            }
            cand.idx[cand.count - 1] = arr[i - 1].id;
            qsort(cand.idx, cand.count, sizeof(int), compareIndices);

            if (compareStates(&cand, &dp[i][k]) > 0) {
                dp[i][k] = cand;
            }
        }
    }

    DPState best = dp[intervalsSize][0];
    for (int k = 1; k <= 4; k++) {
        if (compareStates(&dp[intervalsSize][k], &best) > 0) {
            best = dp[intervalsSize][k];
        }
    }

    *returnSize = best.count;
    int* result = (int*)malloc(sizeof(int) * best.count);
    for (int i = 0; i < best.count; i++) {
        result[i] = best.idx[i];
    }

    for (int i = 0; i <= intervalsSize; i++) {
        free(dp[i]);
    }
    free(dp);
    free(arr);

    return result;
}