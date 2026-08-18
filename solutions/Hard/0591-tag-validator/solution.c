// ──────────────────────────────────────────────────
// Problem  : 591. Tag Validator
// Difficulty: Hard
// Tags     : String, Stack
// Link     : https://leetcode.com/problems/tag-validator/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8428000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValidTagName(const char* name, int len) {
    if (len < 1 || len > 9) return false;
    for (int i = 0; i < len; i++) {
        if (name[i] < 'A' || name[i] > 'Z') return false;
    }
    return true;
}

bool isValid(char* code) {
    int n = strlen(code);
    char* stack[1000];
    int top = -1;
    int i = 0;

    while (i < n) {
        if (i > 0 && top == -1) return false;

        if (strncmp(code + i, "<![CDATA[", 9) == 0) {
            if (top == -1) return false;
            
            char* cdata_end = strstr(code + i + 9, "]]>");
            if (!cdata_end) return false;
            
            i = (cdata_end - code) + 3;
        } 
        else if (strncmp(code + i, "</", 2) == 0) {
            int j = i + 2;
            char* tag_end = strchr(code + j, '>');
            if (!tag_end) return false;
            
            int tag_len = tag_end - (code + j);
            if (!isValidTagName(code + j, tag_len)) return false;
            if (top == -1) return false;

            if (strncmp(stack[top], code + j, tag_len) != 0 || strlen(stack[top]) != tag_len) {
                return false;
            }

            free(stack[top--]);
            i = (tag_end - code) + 1;
        } 
        else if (code[i] == '<') {
            int j = i + 1;
            char* tag_end = strchr(code + j, '>');
            if (!tag_end) return false;

            int tag_len = tag_end - (code + j);
            if (!isValidTagName(code + j, tag_len)) return false;

            char* tag_name = (char*)malloc(tag_len + 1);
            strncpy(tag_name, code + j, tag_len);
            tag_name[tag_len] = '\0';
            
            stack[++top] = tag_name;
            i = (tag_end - code) + 1;
        } 
        else {
            i++;
        }
    }

    while (top >= 0) {
        free(stack[top--]);
    }

    return top == -1;
}