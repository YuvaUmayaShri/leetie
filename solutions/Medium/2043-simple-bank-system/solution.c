// ──────────────────────────────────────────────────
// Problem  : 2043. Simple Bank System
// Difficulty: Medium
// Tags     : Array, Hash Table, Design, Simulation
// Link     : https://leetcode.com/problems/simple-bank-system/
// Runtime  : 3 ms (beats 100%)
// Memory   : 56180000 (beats 90%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct {
    long long* balance;
    int size;
} Bank;

Bank* bankCreate(long long* balance, int balanceSize) {
    Bank* obj = (Bank*)malloc(sizeof(Bank));
    obj->balance = balance;
    obj->size = balanceSize;
    return obj;
}

bool bankTransfer(Bank* obj, int account1, int account2, long long money) {
    if (account1 < 1 || account1 > obj->size || account2 < 1 || account2 > obj->size) {
        return false;
    }
    if (obj->balance[account1 - 1] < money) {
        return false;
    }
    obj->balance[account1 - 1] -= money;
    obj->balance[account2 - 1] += money;
    return true;
}

bool bankDeposit(Bank* obj, int account, long long money) {
    if (account < 1 || account > obj->size) {
        return false;
    }
    obj->balance[account - 1] += money;
    return true;
}

bool bankWithdraw(Bank* obj, int account, long long money) {
    if (account < 1 || account > obj->size) {
        return false;
    }
    if (obj->balance[account - 1] < money) {
        return false;
    }
    obj->balance[account - 1] -= money;
    return true;
}

void bankFree(Bank* obj) {
    free(obj);
}