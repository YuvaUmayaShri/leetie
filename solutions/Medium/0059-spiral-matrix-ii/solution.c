// ──────────────────────────────────────────────────
// Problem  : 59. Spiral Matrix II
// Difficulty: Medium
// Tags     : Array, Matrix, Simulation
// Link     : https://leetcode.com/problems/spiral-matrix-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8332000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    int i = 0;
    int k = 0;
    int cell = 1;
    int digit = 0;
    int **valid = malloc(n * sizeof(int*));
    if (!(valid))
        return (NULL);
    while (k < n)
    {
        i = 0;
        valid[k] = malloc(n * sizeof(int));
        if (!(valid[k]))
            return (NULL);
        while (i < n)
            valid[k][i++] = 1;
        k++;
    }
    i = 0;
    int **map = malloc(n * sizeof(int *)); // matrix arrays
    if (!map)
        return (0);
    while (i < n)
    {
        map[i++] = malloc(n * sizeof(int)); // matrix ints
        if (!map[i - 1])
            return (NULL);
    }
    i = 0;
    *returnSize = n;
    *returnColumnSizes = malloc(n * sizeof(int)); // returnColumnSizes
    if (!(*returnColumnSizes))
        return (0);
    while (i < n)
        (*returnColumnSizes)[i++] = n;
    i = 0;
    k = 0;
    if (n == 1)
    {
        map[i][k] = 1;
        return (map);
    }
    while ((cell - 1) < (n * n))
    {
        while (valid[i][k]) // going right
        {
            map[i][k] = cell++;
            valid[i][k] = 0;
            if (k < n - 1 && valid[i][k + 1])
                k++;
            else
            {
                i++;
                break ;
            }
        }
        while (valid[i][k]) // going down
        {
            map[i][k] = cell++;
            valid[i][k] = 0;
            if (i < n - 1 && valid[i + 1][k])
                i++;
            else
            {
                k--;
                break ;
            }
        }
        while (valid[i][k]) // going left
        {
            map[i][k] = cell++;
            valid[i][k] = 0;
            if (k && valid[i][k - 1])
                k--;
            else
            {
                i--;
                break ;
            }
        }
        while (valid[i][k]) // going up
        {
            map[i][k] = cell++;
            valid[i][k] = 0;
            if (i && valid[i - 1][k])
                i--;
            else
            {
                k++;
                break ;
            }
        }
    }
    return (map);
}