// ──────────────────────────────────────────────────
// Problem  : 1178. Number of Valid Words for Each Puzzle
// Difficulty: Hard
// Tags     : Array, Hash Table, String, Bit Manipulation, Trie
// Link     : https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
// Runtime  : 132 ms (beats 0%)
// Memory   : 66492000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int* findNumOfValidWords(char** words, int wordsSize, char** puzzles, int puzzlesSize, int* returnSize) {
    int maxMask = 1 << 26;
    int* count = (int*)calloc(maxMask, sizeof(int));

    for (int i = 0; i < wordsSize; i++) {
        int mask = 0;
        for (int j = 0; words[i][j] != '\0'; j++) {
            mask |= (1 << (words[i][j] - 'a'));
        }
        count[mask]++;
    }

    int* result = (int*)malloc(puzzlesSize * sizeof(int));
    *returnSize = puzzlesSize;

    for (int i = 0; i < puzzlesSize; i++) {
        int firstCharBit = 1 << (puzzles[i][0] - 'a');
        int mask = 0;
        for (int j = 0; puzzles[i][j] != '\0'; j++) {
            mask |= (1 << (puzzles[i][j] - 'a'));
        }

        int total = 0;
        int submask = mask;

        while (submask > 0) {
            if (submask & firstCharBit) {
                total += count[submask];
            }
            submask = (submask - 1) & mask;
        }

        result[i] = total;
    }

    free(count);
    return result;
}