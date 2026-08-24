// ──────────────────────────────────────────────────
// Problem  : 948. Bag of Tokens
// Difficulty: Medium
// Tags     : Array, Two Pointers, Greedy, Sorting
// Link     : https://leetcode.com/problems/bag-of-tokens/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8484000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int bagOfTokensScore(int* tokens, int tokensSize, int power) {
    qsort(tokens, tokensSize, sizeof(int), compare);
    
    int left = 0;
    int right = tokensSize - 1;
    int score = 0;
    int maxScore = 0;
    
    while (left <= right) {
        if (power >= tokens[left]) {
            power -= tokens[left++];
            score++;
            if (score > maxScore) {
                maxScore = score;
            }
        } else if (score > 0) {
            power += tokens[right--];
            score--;
        } else {
            break;
        }
    }
    
    return maxScore;
}