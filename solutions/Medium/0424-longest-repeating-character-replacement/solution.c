// ──────────────────────────────────────────────────
// Problem  : 424. Longest Repeating Character Replacement
// Difficulty: Medium
// Tags     : Hash Table, String, Sliding Window
// Link     : https://leetcode.com/problems/longest-repeating-character-replacement/
// Runtime  : 2 ms (beats 59%)
// Memory   : 9464000 (beats 32%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int characterReplacement(char* s, int k) {
    int count[26] = {0};
    int left = 0, maxCount = 0, maxLength = 0;
    int len = strlen(s);

    for (int right = 0; right < len; right++) {
        count[s[right] - 'A']++;
        if (count[s[right] - 'A'] > maxCount) {
            maxCount = count[s[right] - 'A'];
        }

        while ((right - left + 1) - maxCount > k) {
            count[s[left] - 'A']--;
            left++;
        }

        int currentLen = right - left + 1;
        if (currentLen > maxLength) {
            maxLength = currentLen;
        }
    }

    return maxLength;
}