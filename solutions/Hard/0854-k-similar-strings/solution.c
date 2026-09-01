// ──────────────────────────────────────────────────
// Problem  : 854. K-Similar Strings
// Difficulty: Hard
// Tags     : Hash Table, String, Breadth-First Search
// Link     : https://leetcode.com/problems/k-similar-strings/
// Runtime  : 244 ms (beats 50%)
// Memory   : 73040000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* str;
    int dist;
} QueueItem;

char* swapChar(const char* s, int i, int j) {
    char* res = strdup(s);
    char temp = res[i];
    res[i] = res[j];
    res[j] = temp;
    return res;
}

int kSimilarity(char* s1, char* s2) {
    if (strcmp(s1, s2) == 0) return 0;

    int n = strlen(s1);
    int capacity = 10000;
    QueueItem* queue = (QueueItem*)malloc(capacity * sizeof(QueueItem));
    int head = 0, tail = 0;

    // Simple hash set using array of string buckets to avoid visited duplication
    int hash_size = 10007;
    typedef struct Node {
        char* str;
        struct Node* next;
    } Node;
    Node** visited = (Node**)calloc(hash_size, sizeof(Node*));

    queue[tail++] = (QueueItem){strdup(s1), 0};

    auto unsigned int hash(const char* str) {
        unsigned int h = 0;
        while (*str) h = h * 31 + *str++;
        return h % hash_size;
    }

    auto void add_visited(const char* str) {
        unsigned int h = hash(str);
        Node* node = (Node*)malloc(sizeof(Node));
        node->str = strdup(str);
        node->next = visited[h];
        visited[h] = node;
    }

    auto int is_visited(const char* str) {
        unsigned int h = hash(str);
        Node* curr = visited[h];
        while (curr) {
            if (strcmp(curr->str, str) == 0) return 1;
            curr = curr->next;
        }
        return 0;
    }

    add_visited(s1);

    int result = 0;

    while (head < tail) {
        QueueItem curr = queue[head++];
        char* curr_str = curr.str;
        int dist = curr.dist;

        if (strcmp(curr_str, s2) == 0) {
            result = dist;
            free(curr_str);
            break;
        }

        int i = 0;
        while (curr_str[i] == s2[i]) i++;

        for (int j = i + 1; j < n; j++) {
            if (curr_str[j] == s2[i]) {
                char* next_str = swapChar(curr_str, i, j);
                if (!is_visited(next_str)) {
                    add_visited(next_str);
                    if (tail >= capacity) {
                        capacity *= 2;
                        queue = (QueueItem*)realloc(queue, capacity * sizeof(QueueItem));
                    }
                    queue[tail++] = (QueueItem){next_str, dist + 1};
                } else {
                    free(next_str);
                }
            }
        }
        free(curr_str);
    }

    // Free memory
    for (int i = head; i < tail; i++) free(queue[i].str);
    free(queue);
    for (int i = 0; i < hash_size; i++) {
        Node* curr = visited[i];
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            free(tmp->str);
            free(tmp);
        }
    }
    free(visited);

    return result;
}