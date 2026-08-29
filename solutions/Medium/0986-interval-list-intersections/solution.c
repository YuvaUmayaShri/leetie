// ──────────────────────────────────────────────────
// Problem  : 986. Interval List Intersections
// Difficulty: Medium
// Tags     : Array, Two Pointers, Sweep Line
// Link     : https://leetcode.com/problems/interval-list-intersections/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8592000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>
#include <math.h>

int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes) {
    int maxCapacity = firstListSize + secondListSize;
    int** res = (int**)malloc(maxCapacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxCapacity * sizeof(int));
    
    int i = 0, j = 0, count = 0;
    
    while (i < firstListSize && j < secondListSize) {
        int start = firstList[i][0] > secondList[j][0] ? firstList[i][0] : secondList[j][0];
        int end = firstList[i][1] < secondList[j][1] ? firstList[i][1] : secondList[j][1];
        
        if (start <= end) {
            res[count] = (int*)malloc(2 * sizeof(int));
            res[count][0] = start;
            res[count][1] = end;
            (*returnColumnSizes)[count] = 2;
            count++;
        }
        
        if (firstList[i][1] < secondList[j][1]) {
            i++;
        } else {
            j++;
        }
    }
    
    *returnSize = count;
    return res;
}