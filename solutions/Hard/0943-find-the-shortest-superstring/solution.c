// ──────────────────────────────────────────────────
// Problem  : 943. Find the Shortest Superstring
// Difficulty: Hard
// Tags     : Array, String, Dynamic Programming, Bit Manipulation, Bitmask, Hamiltonian Path
// Link     : https://leetcode.com/problems/find-the-shortest-superstring/
// Runtime  : 19 ms (beats 86%)
// Memory   : 9268000 (beats 57%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int getOverlap(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    for (int k = lenB; k > 0; k--) {
        if (lenA >= k) {
            if (strncmp(a + lenA - k, b, k) == 0) {
                return k;
            }
        }
    }
    return 0;
}

char* shortestSuperstring(char** words, int wordsSize) {
    int n = wordsSize;
    int overlap[12][12];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                overlap[i][j] = getOverlap(words[i], words[j]);
            } else {
                overlap[i][j] = 0;
            }
        }
    }

    int numStates = 1 << n;
    int dp[1 << 12][12];
    int parent[1 << 12][12];
    
    for (int mask = 0; mask < numStates; mask++) {
        for (int i = 0; i < n; i++) {
            dp[mask][i] = -1;
            parent[mask][i] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
    }

    for (int mask = 1; mask < numStates; mask++) {
        for (int last = 0; last < n; last++) {
            if (dp[mask][last] == -1) continue;

            for (int next = 0; next < n; next++) {
                if (!(mask & (1 << next))) {
                    int nextMask = mask | (1 << next);
                    int val = dp[mask][last] + overlap[last][next];
                    if (val > dp[nextMask][next]) {
                        dp[nextMask][next] = val;
                        parent[nextMask][next] = last;
                    }
                }
            }
        }
    }

    int maxOverlap = -1;
    int lastNode = -1;
    int finalMask = numStates - 1;

    for (int i = 0; i < n; i++) {
        if (dp[finalMask][i] > maxOverlap) {
            maxOverlap = dp[finalMask][i];
            lastNode = i;
        }
    }

    int path[12];
    int pathSize = 0;
    int currMask = finalMask;
    int currNode = lastNode;

    while (currNode != -1) {
        path[pathSize++] = currNode;
        int prevNode = parent[currMask][currNode];
        currMask ^= (1 << currNode);
        currNode = prevNode;
    }

    char* result = (char*)malloc(250 * sizeof(char));
    result[0] = '\0';

    int firstIdx = path[pathSize - 1];
    strcpy(result, words[firstIdx]);

    for (int i = pathSize - 2; i >= 0; i--) {
        int prevIdx = path[i + 1];
        int currIdx = path[i];
        int ol = overlap[prevIdx][currIdx];
        strcat(result, words[currIdx] + ol);
    }

    return result;
}