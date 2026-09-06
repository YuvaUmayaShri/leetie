// ──────────────────────────────────────────────────
// Problem  : 1763. Longest Nice Substring
// Difficulty: Easy
// Tags     : Hash Table, String, Divide and Conquer, Bit Manipulation, Sliding Window
// Link     : https://leetcode.com/problems/longest-nice-substring/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8436000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

char* longestNiceSubstring(char* s) {
    int len = strlen(s);
    if (len < 2) return "";

    for (int i = 0; i < len; i++) {
        char c = s[i];
        int found = 0;
        for (int j = 0; j < len; j++) {
            if ((c >= 'a' && c <= 'z' && s[j] == c - 32) ||
                (c >= 'A' && c <= 'Z' && s[j] == c + 32)) {
                found = 1;
                break;
            }
        }

        if (!found) {
            char leftStr[100] = {0};
            char rightStr[100] = {0};

            strncpy(leftStr, s, i);
            leftStr[i] = '\0';
            strcpy(rightStr, s + i + 1);

            char* sub1 = longestNiceSubstring(leftStr);
            char* sub2 = longestNiceSubstring(rightStr);

            if (strlen(sub1) >= strlen(sub2)) {
                return sub1;
            } else {
                return sub2;
            }
        }
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));
    strcpy(result, s);
    return result;
}