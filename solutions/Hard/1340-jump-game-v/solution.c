// ──────────────────────────────────────────────────
// Problem  : 1340. Jump Game V
// Difficulty: Hard
// Tags     : Array, Dynamic Programming, Sorting
// Link     : https://leetcode.com/problems/jump-game-v/
// Runtime  : 161 ms (beats 8%)
// Memory   : 205276000 (beats 8%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int maxJumps(int* arr, int arrSize, int d) {
    int n = arrSize;
    int* steps = (int*)malloc(sizeof(int) * n);
    int* stack = (int*)malloc(sizeof(int) * n);
    int top = 0;
    for (int i = 0; i < n; i++) {
        steps[i] = 1;
    }
    for (int i = 0; i <= n; i++) {
        while (top > 0 && (i == n || arr[stack[top - 1]] < arr[i])) {
            int* pop_indices = (int*)malloc(sizeof(int) * n);
            int popSize = 0;
            pop_indices[popSize++] = stack[--top];
            while (top > 0 && arr[stack[top - 1]] == arr[pop_indices[0]]) {
                pop_indices[popSize++] = stack[--top];
            }
            for (int p = 0; p < popSize; p++) {
                int j = pop_indices[p];
                if (i < n && i - j <= d) {
                    int val = steps[j] + 1;
                    if (val > steps[i])
                        steps[i] = val;
                }
                if (top > 0 && j - stack[top - 1] <= d) {
                    int leftIdx = stack[top - 1];
                    int val = steps[j] + 1;
                    if (val > steps[leftIdx])
                        steps[leftIdx] = val;
                }
            }
            free(pop_indices);
        }
        if (i < n) {
            stack[top++] = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (steps[i] > ans)
            ans = steps[i];
    }
    free(steps);
    free(stack);
    return ans;
}