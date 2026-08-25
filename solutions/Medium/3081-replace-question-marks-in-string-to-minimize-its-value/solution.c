// ──────────────────────────────────────────────────
// Problem  : 3081. Replace Question Marks in String to Minimize Its Value
// Difficulty: Medium
// Tags     : Hash Table, String, Greedy, Sorting, Heap (Priority Queue), Counting
// Link     : https://leetcode.com/problems/replace-question-marks-in-string-to-minimize-its-value/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8360000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* minimizeStringValue(char* s) {
    int n = strlen(s);
    int freq[26] = {0};
    int q_count = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            freq[s[i] - 'a']++;
        } else {
            q_count++;
        }
    }

    int add_freq[26] = {0};

    for (int i = 0; i < q_count; i++) {
        int best_char = 0;
        int min_freq = freq[0];
        for (int c = 1; c < 26; c++) {
            if (freq[c] < min_freq) {
                min_freq = freq[c];
                best_char = c;
            }
        }
        freq[best_char]++;
        add_freq[best_char]++;
    }

    char* new_s = (char*)malloc(sizeof(char) * (n + 1));
    strcpy(new_s, s);

    int char_idx = 0;
    for (int i = 0; i < n; i++) {
        if (new_s[i] == '?') {
            while (add_freq[char_idx] == 0) {
                char_idx++;
            }
            new_s[i] = 'a' + char_idx;
            add_freq[char_idx]--;
        }
    }

    return new_s;
}