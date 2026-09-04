// ──────────────────────────────────────────────────
// Problem  : 1601. Maximum Number of Achievable Transfer Requests
// Difficulty: Hard
// Tags     : Array, Backtracking, Bit Manipulation, Enumeration
// Link     : https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8588000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

void backtrack(int** requests, int requestsSize, int n, int index, int count, int* netChange, int* maxRequests) {
    if (index == requestsSize) {
        for (int i = 0; i < n; i++) {
            if (netChange[i] != 0) {
                return;
            }
        }
        if (count > *maxRequests) {
            *maxRequests = count;
        }
        return;
    }

    int from = requests[index][0];
    int to = requests[index][1];

    netChange[from]--;
    netChange[to]++;
    backtrack(requests, requestsSize, n, index + 1, count + 1, netChange, maxRequests);

    netChange[from]++;
    netChange[to]--;
    backtrack(requests, requestsSize, n, index + 1, count, netChange, maxRequests);
}

int maximumRequests(int n, int** requests, int requestsSize, int* requestsColSize) {
    int* netChange = (int*)calloc(n, sizeof(int));
    int maxRequests = 0;

    backtrack(requests, requestsSize, n, 0, 0, netChange, &maxRequests);

    free(netChange);
    return maxRequests;
}