// ──────────────────────────────────────────────────
// Problem  : 335. Self Crossing
// Difficulty: Hard
// Tags     : Array, Math, Geometry
// Link     : https://leetcode.com/problems/self-crossing/
// Runtime  : 2 ms (beats 32%)
// Memory   : 13364000 (beats 75%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool isSelfCrossing(int* distance, int distanceSize) {
    if (distanceSize <= 3) {
        return false;
    }
    
    for (int i = 3; i < distanceSize; i++) {
        if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3]) {
            return true;
        }
        
        if (i >= 4 && distance[i - 1] == distance[i - 3] && distance[i] + distance[i - 4] >= distance[i - 2]) {
            return true;
        }
        
        if (i >= 5 && distance[i - 2] >= distance[i - 4] && distance[i - 3] >= distance[i - 1] && 
            distance[i - 1] + distance[i - 5] >= distance[i - 3] && distance[i] + distance[i - 4] >= distance[i - 2]) {
            return true;
        }
    }
    
    return false;
}