// ──────────────────────────────────────────────────
// Problem  : 721. Accounts Merge
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Depth-First Search, Breadth-First Search, Union-Find, Sorting
// Link     : https://leetcode.com/problems/accounts-merge/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8680000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int parent;
} DSU;

int find(DSU* dsu, int i) {
    if (dsu[i].parent == i)
        return i;
    return dsu[i].parent = find(dsu, dsu[i].parent);
}

void unionSet(DSU* dsu, int i, int j) {
    int root_i = find(dsu, i);
    int root_j = find(dsu, j);
    if (root_i != root_j) {
        dsu[root_i].parent = root_j;
    }
}

int cmpString(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

typedef struct {
    char* email;
    int account_idx;
} EmailMap;

int cmpEmailMap(const void* a, const void* b) {
    return strcmp(((EmailMap*)a)->email, ((EmailMap*)b)->email);
}

char*** accountsMerge(char*** accounts, int accountsSize, int* accountsColSize, int* returnSize, int** returnColumnSizes) {
    DSU* dsu = (DSU*)malloc(accountsSize * sizeof(DSU));
    for (int i = 0; i < accountsSize; i++) {
        dsu[i].parent = i;
    }

    int total_emails = 0;
    for (int i = 0; i < accountsSize; i++) {
        total_emails += (accountsColSize[i] - 1);
    }

    EmailMap* email_list = (EmailMap*)malloc(total_emails * sizeof(EmailMap));
    int email_cnt = 0;

    for (int i = 0; i < accountsSize; i++) {
        for (int j = 1; j < accountsColSize[i]; j++) {
            email_list[email_cnt].email = accounts[i][j];
            email_list[email_cnt].account_idx = i;
            email_cnt++;
        }
    }

    qsort(email_list, email_cnt, sizeof(EmailMap), cmpEmailMap);

    for (int i = 0; i < email_cnt; i++) {
        if (i > 0 && strcmp(email_list[i].email, email_list[i - 1].email) == 0) {
            unionSet(dsu, email_list[i].account_idx, email_list[i - 1].account_idx);
        }
    }

    int* unique_root_ids = (int*)malloc(accountsSize * sizeof(int));
    int unique_cnt = 0;

    int* root_to_group = (int*)malloc(accountsSize * sizeof(int));
    for (int i = 0; i < accountsSize; i++) root_to_group[i] = -1;

    for (int i = 0; i < accountsSize; i++) {
        int root = find(dsu, i);
        if (root_to_group[root] == -1) {
            root_to_group[root] = unique_cnt;
            unique_root_ids[unique_cnt] = root;
            unique_cnt++;
        }
    }

    int* group_sizes = (int*)calloc(unique_cnt, sizeof(int));
    for (int i = 0; i < email_cnt; i++) {
        if (i == 0 || strcmp(email_list[i].email, email_list[i - 1].email) != 0) {
            int root = find(dsu, email_list[i].account_idx);
            int group = root_to_group[root];
            group_sizes[group]++;
        }
    }

    char*** result = (char***)malloc(unique_cnt * sizeof(char**));
    *returnColumnSizes = (int*)malloc(unique_cnt * sizeof(int));
    *returnSize = unique_cnt;

    for (int i = 0; i < unique_cnt; i++) {
        int num_emails = group_sizes[i];
        (*returnColumnSizes)[i] = num_emails + 1;
        result[i] = (char**)malloc((num_emails + 1) * sizeof(char*));
        int orig_acc_idx = unique_root_ids[i];
        result[i][0] = accounts[orig_acc_idx][0];
    }

    int* current_pos = (int*)calloc(unique_cnt, sizeof(int));

    for (int i = 0; i < email_cnt; i++) {
        if (i == 0 || strcmp(email_list[i].email, email_list[i - 1].email) != 0) {
            int root = find(dsu, email_list[i].account_idx);
            int group = root_to_group[root];
            result[group][1 + current_pos[group]] = email_list[i].email;
            current_pos[group]++;
        }
    }

    for (int i = 0; i < unique_cnt; i++) {
        qsort(result[i] + 1, group_sizes[i], sizeof(char*), cmpString);
    }

    free(dsu);
    free(email_list);
    free(unique_root_ids);
    free(root_to_group);
    free(group_sizes);
    free(current_pos);

    return result;
}