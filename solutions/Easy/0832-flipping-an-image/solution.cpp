// ──────────────────────────────────────────────────
// Problem  : 832. Flipping an Image
// Difficulty: Easy
// Tags     : Array, Two Pointers, Bit Manipulation, Matrix, Simulation
// Link     : https://leetcode.com/problems/flipping-an-image/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8428000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image) {
        int n = image.size();
        for (int i = 0; i < n; i++) {
            int left = 0, right = n - 1;
            while (left <= right) {
                if (left == right) {
                    image[i][left] ^= 1;
                } else if (image[i][left] == image[i][right]) {
                    image[i][left] ^= 1;
                    image[i][right] ^= 1;
                }
                left++;
                right--;
            }
        }
        return image;
    }
};