// ──────────────────────────────────────────────────
// Problem  : 514. Freedom Trail
// Difficulty: Hard
// Tags     : String, Dynamic Programming, Depth-First Search, Breadth-First Search
// Link     : https://leetcode.com/problems/freedom-trail/
// Runtime  : 3 ms (beats 82%)
// Memory   : 9988000 (beats 36%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int findRotateSteps(char* ring, char* key) {
    int r_len = strlen(ring);
    int k_len = strlen(key);

    int pos[26][100];
    int pos_cnt[26] = {0};
    for (int i = 0; i < r_len; i++) {
        int idx = ring[i] - 'a';
        pos[idx][pos_cnt[idx]++] = i;
    }

    int dp[100];
    int first_char = key[0] - 'a';
    for (int i = 0; i < pos_cnt[first_char]; i++) {
        int p = pos[first_char][i];
        int dist = abs(p - 0);
        dp[i] = (dist < r_len - dist ? dist : r_len - dist) + 1;
    }

    for (int i = 1; i < k_len; i++) {
        int prev_char = key[i - 1] - 'a';
        int curr_char = key[i] - 'a';
        int next_dp[100];

        for (int j = 0; j < pos_cnt[curr_char]; j++) {
            int curr_pos = pos[curr_char][j];
            int min_steps = 1e9;

            for (int k = 0; k < pos_cnt[prev_char]; k++) {
                int prev_pos = pos[prev_char][k];
                int dist = abs(curr_pos - prev_pos);
                int step = (dist < r_len - dist ? dist : r_len - dist) + 1;
                if (dp[k] + step < min_steps) {
                    min_steps = dp[k] + step;
                }
            }
            next_dp[j] = min_steps;
        }

        for (int j = 0; j < pos_cnt[curr_char]; j++) {
            dp[j] = next_dp[j];
        }
    }

    int last_char = key[k_len - 1] - 'a';
    int ans = dp[0];
    for (int i = 1; i < pos_cnt[last_char]; i++) {
        if (dp[i] < ans) {
            ans = dp[i];
        }
    }

    return ans;
}