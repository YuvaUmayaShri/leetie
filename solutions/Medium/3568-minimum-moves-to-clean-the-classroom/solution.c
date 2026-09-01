// ──────────────────────────────────────────────────
// Problem  : 3568. Minimum Moves to Clean the Classroom
// Difficulty: Medium
// Tags     : Array, Hash Table, Bit Manipulation, Breadth-First Search, Matrix
// Link     : https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8576000 (beats 0%)
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
    
    if (litter_count == 0) return 0;
    
    int num_masks = 1 << litter_count;
    int target_mask = num_masks - 1;
    
    int* max_energy = (int*)malloc(m * n * num_masks * sizeof(int));
    memset(max_energy, -1, m * n * num_masks * sizeof(int));
    
    int queue_capacity = m * n * num_masks;
    State* queue = (State*)malloc(queue_capacity * sizeof(State));
    int head = 0, tail = 0;
    
    queue[tail++] = (State){start_r, start_c, 0, energy, 0};
    max_energy[(start_r * n + start_c) * num_masks + 0] = energy;
    
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    while (head < tail) {
        State curr = queue[head++];
        int curr_idx = (curr.r * n + curr.c) * num_masks + curr.mask;
        
        if (curr.energy < max_energy[curr_idx]) {
            continue;
        }
        
        for (int d = 0; d < 4; d++) {
            int nr = curr.r + dirs[d][0];
            int nc = curr.c + dirs[d][1];
            
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                if (curr.energy - 1 < 0) continue;
                
                int next_e = curr.energy - 1;
                int next_mask = curr.mask;
                char cell = classroom[nr][nc];
                
                if (cell == 'R') {
                    next_e = energy;
                }
                
                if (cell == 'L') {
                    next_mask |= (1 << litter_map[nr][nc]);
                }
                
                if (next_mask == target_mask) {
                    int result = curr.moves + 1;
                    free(max_energy);
                    free(queue);
                    return result;
                }
                
                int next_idx = (nr * n + nc) * num_masks + next_mask;
                if (next_e > max_energy[next_idx]) {
                    max_energy[next_idx] = next_e;
                    queue[tail++] = (State){nr, nc, next_mask, next_e, curr.moves + 1};
                }
            }
        }
    }
    
    free(max_energy);
    free(queue);
    return -1;
}