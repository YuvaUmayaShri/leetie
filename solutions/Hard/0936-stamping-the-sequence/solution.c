// ──────────────────────────────────────────────────
// Problem  : 936. Stamping The Sequence
// Difficulty: Hard
// Tags     : String, Stack, Greedy, Queue
// Link     : https://leetcode.com/problems/stamping-the-sequence/
// Runtime  : 6 ms (beats 43%)
// Memory   : 12736000 (beats 29%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool canStamp(char* stamp, char* target, int pos, int m) {
    bool hasNonQuestion = false;
    for (int i = 0; i < m; i++) {
        if (target[pos + i] != '?') {
            if (target[pos + i] != stamp[i]) {
                return false;
            }
            hasNonQuestion = true;
        }
    }
    return hasNonQuestion;
}

int doStamp(char* target, int pos, int m) {
    int cleared = 0;
    for (int i = 0; i < m; i++) {
        if (target[pos + i] != '?') {
            target[pos + i] = '?';
            cleared++;
        }
    }
    return cleared;
}

int* movesToStamp(char* stamp, char* target, int* returnSize) {
    int m = strlen(stamp);
    int n = strlen(target);
    
    int* res = (int*)malloc(n * 10 * sizeof(int));
    bool* visited = (bool*)calloc(n, sizeof(bool));
    
    int stars = 0;
    int resCount = 0;
    
    while (stars < n) {
        bool stamped = false;
        
        for (int i = 0; i <= n - m; i++) {
            if (!visited[i] && canStamp(stamp, target, i, m)) {
                stars += doStamp(target, i, m);
                res[resCount++] = i;
                visited[i] = true;
                stamped = true;
                
                if (stars == n) {
                    break;
                }
            }
        }
        
        if (!stamped) {
            *returnSize = 0;
            free(res);
            free(visited);
            return NULL;
        }
    }
    
    for (int i = 0; i < resCount / 2; i++) {
        int temp = res[i];
        res[i] = res[resCount - 1 - i];
        res[resCount - 1 - i] = temp;
    }
    
    free(visited);
    *returnSize = resCount;
    return res;
}