// ──────────────────────────────────────────────────
// Problem  : 2296. Design a Text Editor
// Difficulty: Hard
// Tags     : Linked List, String, Stack, Design, Simulation, Doubly-Linked List
// Link     : https://leetcode.com/problems/design-a-text-editor/
// Runtime  : 47 ms (beats 29%)
// Memory   : 75108000 (beats 71%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#define MAX_LEN 800005

typedef struct {
    char left[MAX_LEN];
    int leftLen;
    char right[MAX_LEN];
    int rightLen;
    char res[15];
} TextEditor;

TextEditor* textEditorCreate() {
    TextEditor* obj = (TextEditor*)malloc(sizeof(TextEditor));
    obj->leftLen = 0;
    obj->rightLen = 0;
    return obj;
}

void textEditorAddText(TextEditor* obj, char* text) {
    while (*text) {
        obj->left[obj->leftLen++] = *text;
        text++;
    }
}

int textEditorDeleteText(TextEditor* obj, int k) {
    int deleted = k < obj->leftLen ? k : obj->leftLen;
    obj->leftLen -= deleted;
    return deleted;
}

char* textEditorCursorLeft(TextEditor* obj, int k) {
    int move = k < obj->leftLen ? k : obj->leftLen;
    for (int i = 0; i < move; i++) {
        obj->right[obj->rightLen++] = obj->left[--obj->leftLen];
    }
    
    int len = 10 < obj->leftLen ? 10 : obj->leftLen;
    for (int i = 0; i < len; i++) {
        obj->res[i] = obj->left[obj->leftLen - len + i];
    }
    obj->res[len] = '\0';
    return obj->res;
}

char* textEditorCursorRight(TextEditor* obj, int k) {
    int move = k < obj->rightLen ? k : obj->rightLen;
    for (int i = 0; i < move; i++) {
        obj->left[obj->leftLen++] = obj->right[--obj->rightLen];
    }
    
    int len = 10 < obj->leftLen ? 10 : obj->leftLen;
    for (int i = 0; i < len; i++) {
        obj->res[i] = obj->left[obj->leftLen - len + i];
    }
    obj->res[len] = '\0';
    return obj->res;
}

void textEditorFree(TextEditor* obj) {
    free(obj);
}

/**
 * Your TextEditor struct will be instantiated and called as such:
 * TextEditor* obj = textEditorCreate();
 * textEditorAddText(obj, text);
 * int param_2 = textEditorDeleteText(obj, k);
 * char* param_3 = textEditorCursorLeft(obj, k);
 * char* param_4 = textEditorCursorRight(obj, k);
 * textEditorFree(obj);
 */