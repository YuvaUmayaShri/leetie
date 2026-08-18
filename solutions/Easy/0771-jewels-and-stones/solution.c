// ──────────────────────────────────────────────────
// Problem  : 771. Jewels and Stones
// Difficulty: Easy
// Tags     : Hash Table, String
// Link     : https://leetcode.com/problems/jewels-and-stones/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8764000 (beats 39%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <string.h>

int numJewelsInStones(char* jewels, char* stones) {
    bool isJewel[128] = {false};
    int count = 0;

    for (int i = 0; jewels[i] != '\0'; i++) {
        isJewel[(unsigned char)jewels[i]] = true;
    }

    for (int i = 0; stones[i] != '\0'; i++) {
        if (isJewel[(unsigned char)stones[i]]) {
            count++;
        }
    }

    return count;
}