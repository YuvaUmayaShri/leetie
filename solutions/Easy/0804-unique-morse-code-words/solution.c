// ──────────────────────────────────────────────────
// Problem  : 804. Unique Morse Code Words
// Difficulty: Easy
// Tags     : Array, Hash Table, String
// Link     : https://leetcode.com/problems/unique-morse-code-words/
// Runtime  : 2 ms (beats 22%)
// Memory   : 9412000 (beats 48%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

const char* MORSE[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

int uniqueMorseRepresentations(char** words, int wordsSize) {
    char transformations[100][49];
    int uniqueCount = 0;

    for (int i = 0; i < wordsSize; i++) {
        char currentMorse[49] = "";
        
        for (int j = 0; words[i][j] != '\0'; j++) {
            strcat(currentMorse, MORSE[words[i][j] - 'a']);
        }

        bool isUnique = true;
        for (int k = 0; k < uniqueCount; k++) {
            if (strcmp(transformations[k], currentMorse) == 0) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            strcpy(transformations[uniqueCount], currentMorse);
            uniqueCount++;
        }
    }

    return uniqueCount;
}