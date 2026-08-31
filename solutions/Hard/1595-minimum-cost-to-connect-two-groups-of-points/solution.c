// ──────────────────────────────────────────────────
// Problem  : 1595. Minimum Cost to Connect Two Groups of Points
// Difficulty: Hard
// Tags     : Array, Dynamic Programming, Bit Manipulation, Matrix, Bitmask, Bipartite Graph, Successive Shortest Path Algorithm, Matching (Graph), Minimum-Cost Flow, Flow Network
// Link     : https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/
// Runtime  : 7 ms (beats 100%)
// Memory   : 10852000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int connectTwoGroups(int** cost, int costSize, int* costColSize) {
    int sz1 = costSize;
    int sz2 = costColSize[0];
    int num_masks = 1 << sz2;

    // Precompute minimum cost to connect each point in group 2 to group 1
    int min_cost_g2[12];
    for (int j = 0; j < sz2; j++) {
        min_cost_g2[j] = INT_MAX;
        for (int i = 0; i < sz1; i++) {
            if (cost[i][j] < min_cost_g2[j]) {
                min_cost_g2[j] = cost[i][j];
            }
        }
    }

    // dp[mask] = minimum cost to connect first i points of group 1 with mask of group 2 connected
    int* dp = (int*)malloc(num_masks * sizeof(int));
    for (int mask = 0; mask < num_masks; mask++) {
        dp[mask] = INT_MAX / 2;
    }
    dp[0] = 0;

    for (int i = 0; i < sz1; i++) {
        int* next_dp = (int*)malloc(num_masks * sizeof(int));
        for (int mask = 0; mask < num_masks; mask++) {
            next_dp[mask] = INT_MAX / 2;
        }

        for (int mask = 0; mask < num_masks; mask++) {
            if (dp[mask] >= INT_MAX / 2) continue;

            for (int j = 0; j < sz2; j++) {
                int next_mask = mask | (1 << j);
                next_dp[next_mask] = min(next_dp[next_mask], dp[mask] + cost[i][j]);
            }
        }
        
        free(dp);
        dp = next_dp;
    }

    // Add minimum costs for any points in group 2 that remain unconnected
    int ans = INT_MAX;
    for (int mask = 0; mask < num_masks; mask++) {
        if (dp[mask] >= INT_MAX / 2) continue;

        int total = dp[mask];
        for (int j = 0; j < sz2; j++) {
            if ((mask & (1 << j)) == 0) {
                total += min_cost_g2[j];
            }
        }
        ans = min(ans, total);
    }

    free(dp);
    return ans;
}