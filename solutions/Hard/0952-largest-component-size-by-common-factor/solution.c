// ──────────────────────────────────────────────────
// Problem  : 952. Largest Component Size by Common Factor
// Difficulty: Hard
// Tags     : Array, Hash Table, Math, Union-Find, Number Theory, Prime Factorization
// Link     : https://leetcode.com/problems/largest-component-size-by-common-factor/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8584000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int find(int* parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSet(int* parent, int i, int j) {
    int rootI = find(parent, i);
    int rootJ = find(parent, j);
    if (rootI != rootJ) {
        parent[rootI] = rootJ;
    }
}

int largestComponentSize(int* nums, int numsSize) {
    int maxVal = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }

    int* parent = (int*)malloc((maxVal + 1) * sizeof(int));
    for (int i = 0; i <= maxVal; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        for (int d = 2; d * d <= num; d++) {
            if (num % d == 0) {
                unionSet(parent, nums[i], d);
                unionSet(parent, nums[i], num / d);
            }
        }
    }

    int* count = (int*)calloc(maxVal + 1, sizeof(int));
    int maxComponent = 0;

    for (int i = 0; i < numsSize; i++) {
        int root = find(parent, nums[i]);
        count[root]++;
        if (count[root] > maxComponent) {
            maxComponent = count[root];
        }
    }

    free(parent);
    free(count);

    return maxComponent;
}