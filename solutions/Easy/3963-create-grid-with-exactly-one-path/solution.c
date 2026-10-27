// ──────────────────────────────────────────────────
// Problem  : 3963. Create Grid With Exactly One Path
// Difficulty: Easy
// Tags     : N/A
// Link     : https://leetcode.com/problems/create-grid-with-exactly-one-path/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8592000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** createGrid(int m, int n, int* returnSize) {
    char** ans=(char**)malloc(m*sizeof(char*));
    ans[0]=(char*)malloc(n+1);
    memset(ans[0], '.', n);
    ans[0][n]='\0';
    for(int i=1; i<m; i++){
        ans[i]=(char*)malloc(n+1);
        memset(ans[i], '#', n-1);
        ans[i][n-1]='.';
        ans[i][n]='\0';
    }
    *returnSize=m;
    return ans;
}