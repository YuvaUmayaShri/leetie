// ──────────────────────────────────────────────────
// Problem  : 1111. Maximum Nesting Depth of Two Valid Parentheses Strings
// Difficulty: Medium
// Tags     : String, Stack, Bracket Sequences
// Link     : https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
// Runtime  : 0 ms (beats 100%)
// Memory   : 13204000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <string.h>

int* maxDepthAfterSplit(char* seq, int* returnSize) {
    int n = strlen(seq);
    *returnSize = n;
    int* ans = (int*)malloc(n * sizeof(int));
    int depth = 0;

    for (int i = 0; i < n; i++) {
        if (seq[i] == '(') {
            depth++;
            ans[i] = depth % 2;
        } else {
            ans[i] = depth % 2;
            depth--;
        }
    }

    return ans;
}