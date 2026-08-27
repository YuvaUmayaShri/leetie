// ──────────────────────────────────────────────────
// Problem  : 202. Happy Number
// Difficulty: Easy
// Tags     : Hash Table, Math, Two Pointers, Floyd's Cycle Finding Algorithm
// Link     : https://leetcode.com/problems/happy-number/
// Runtime  : 0 ms (beats 100%)
// Memory   : 7720000 (beats 82%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
private:
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            totalSum += d * d;
        }
        return totalSum;
    }

public:
    bool isHappy(int n) {
        int slowRunner = n;
        int fastRunner = getNext(n);
        while (fastRunner != 1 && slowRunner != fastRunner) {
            slowRunner = getNext(slowRunner);
            fastRunner = getNext(getNext(fastRunner));
        }
        return fastRunner == 1;
    }
};