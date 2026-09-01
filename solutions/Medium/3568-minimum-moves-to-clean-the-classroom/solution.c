// ──────────────────────────────────────────────────
// Problem  : 3568. Minimum Moves to Clean the Classroom
// Difficulty: Medium
// Tags     : Array, Hash Table, Bit Manipulation, Breadth-First Search, Matrix
// Link     : https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/
// Runtime  : 197 ms (beats 100%)
// Memory   : 102024000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int r;
    int c;
    int mask;
    int energy;
    int moves;
} State;

int minMoves(char** classroom, int classroomSize, int energy) {
    int m = classroomSize;
    int n = strlen(classroom[0]);

    int start_r = -1, start_c = -1;
    int litter_map[20][20];
    memset(litter_map, -1, sizeof(litter_map));
    int litter_count = 0;

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (classroom[r][c] == 'S') {
                start_r = r;
                start_c = c;
            } else if (classroom[r][c] == 'L') {
                litter_map[r][c] = litter_count++;
            }
        }
    }

    int full_mask = (1 << litter_count) - 1;
    if (full_mask == 0) return 0;

    // best_energy[r][c][mask] stores the maximum energy recorded at (r, c) with mask
    int best_energy[20][20][1024];
    memset(best_energy, -1, sizeof(best_energy));

    int capacity = 100000;
    State* queue = (State*)malloc(capacity * sizeof(State));
    int head = 0, tail = 0;

    int start_mask = 0;
    if (classroom[start_r][start_c] == 'L') {
        start_mask |= (1 << litter_map[start_r][start_c]);
    }

    queue[tail++] = (State){start_r, start_c, start_mask, energy, 0};
    best_energy[start_r][start_c][start_mask] = energy;

    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int result = -1;

    while (head < tail) {
        State curr = queue[head++];

        if (curr.mask == full_mask) {
            result = curr.moves;
            break;
        }

        if (curr.energy == 0) continue;

        for (int d = 0; d < 4; d++) {
            int nr = curr.r + dirs[d][0];
            int nc = curr.c + dirs[d][1];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                continue;
            }

            int next_energy = curr.energy - 1;
            char cell = classroom[nr][nc];

            if (cell == 'R') {
                next_energy = energy;
            }

            int next_mask = curr.mask;
            if (cell == 'L' && litter_map[nr][nc] != -1) {
                next_mask |= (1 << litter_map[nr][nc]);
            }

            if (next_energy > best_energy[nr][nc][next_mask]) {
                best_energy[nr][nc][next_mask] = next_energy;

                if (tail >= capacity) {
                    capacity *= 2;
                    queue = (State*)realloc(queue, capacity * sizeof(State));
                }
                queue[tail++] = (State){nr, nc, next_mask, next_energy, curr.moves + 1};
            }
        }
    }

    free(queue);
    return result;
}