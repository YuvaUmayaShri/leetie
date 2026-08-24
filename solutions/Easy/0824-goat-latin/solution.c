// ──────────────────────────────────────────────────
// Problem  : 824. Goat Latin
// Difficulty: Easy
// Tags     : String
// Link     : https://leetcode.com/problems/goat-latin/
// Runtime  : 3 ms (beats 8%)
// Memory   : 9632000 (beats 20%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char* toGoatLatin(char* sentence) {
    char* result = (char*)malloc(4000 * sizeof(char));
    result[0] = '\0';
    
    int wordIndex = 1;
    char* token = strtok(sentence, " ");
    
    while (token != NULL) {
        if (wordIndex > 1) {
            strcat(result, " ");
        }
        
        int len = strlen(token);
        
        if (isVowel(token[0])) {
            strcat(result, token);
        } else {
            strncat(result, token + 1, len - 1);
            char first[2] = {token[0], '\0'};
            strcat(result, first);
        }
        
        strcat(result, "ma");
        
        for (int i = 0; i < wordIndex; i++) {
            strcat(result, "a");
        }
        
        wordIndex++;
        token = strtok(NULL, " ");
    }
    
    return result;
}