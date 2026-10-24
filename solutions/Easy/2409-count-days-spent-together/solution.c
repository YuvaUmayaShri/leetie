// ──────────────────────────────────────────────────
// Problem  : 2409. Count Days Spent Together
// Difficulty: Easy
// Tags     : Math, String
// Link     : https://leetcode.com/problems/count-days-spent-together/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8372000 (beats 75%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int arrA = ((arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0') - 1);
    int depA = ((leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0') - 1);
    int arrB = ((arriveBob[0] - '0') * 10 + (arriveBob[1] - '0') - 1);
    int depB = ((leaveBob[0] - '0') * 10 + (leaveBob[1] - '0') - 1);

    int dayA1 = 0, dayA2 = 0, dayB1 = 0, dayB2 = 0;
    for (int i = 0; i < arrA; i++) dayA1 += days[i];
    dayA1 += (arriveAlice[3] - '0') * 10 + (arriveAlice[4] - '0');

    for (int i = 0; i < depA; i++) dayA2 += days[i];
    dayA2 += (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0');

    for (int i = 0; i < arrB; i++) dayB1 += days[i];
    dayB1 += (arriveBob[3] - '0') * 10 + (arriveBob[4] - '0');

    for (int i = 0; i < depB; i++) dayB2 += days[i];
    dayB2 += (leaveBob[3] - '0') * 10 + (leaveBob[4] - '0');

    int start = dayA1 > dayB1 ? dayA1 : dayB1;
    int end = dayA2 < dayB2 ? dayA2 : dayB2;

    return start <= end ? end - start + 1 : 0;
}