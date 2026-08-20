// ──────────────────────────────────────────────────
// Problem  : 855. Exam Room
// Difficulty: Medium
// Tags     : Design, Heap (Priority Queue), Ordered Set
// Link     : https://leetcode.com/problems/exam-room/
// Runtime  : 169 ms (beats 100%)
// Memory   : 20092000 (beats 100%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

typedef struct {
    int N;
    int* seats;
    int count;
} ExamRoom;

ExamRoom* examRoomCreate(int n) {
    ExamRoom* obj = (ExamRoom*)malloc(sizeof(ExamRoom));
    obj->N = n;
    obj->seats = (int*)malloc(10000 * sizeof(int));
    obj->count = 0;
    return obj;
}

int examRoomSeat(ExamRoom* obj) {
    if (obj->count == 0) {
        obj->seats[0] = 0;
        obj->count++;
        return 0;
    }

    int maxDist = obj->seats[0];
    int seatToTake = 0;
    int insertIdx = 0;

    for (int i = 0; i < obj->count - 1; i++) {
        int dist = (obj->seats[i + 1] - obj->seats[i]) / 2;
        if (dist > maxDist) {
            maxDist = dist;
            seatToTake = obj->seats[i] + dist;
            insertIdx = i + 1;
        }
    }

    if ((obj->N - 1 - obj->seats[obj->count - 1]) > maxDist) {
        seatToTake = obj->N - 1;
        insertIdx = obj->count;
    }

    for (int i = obj->count; i > insertIdx; i--) {
        obj->seats[i] = obj->seats[i - 1];
    }
    obj->seats[insertIdx] = seatToTake;
    obj->count++;

    return seatToTake;
}

void examRoomLeave(ExamRoom* obj, int p) {
    int idx = -1;
    for (int i = 0; i < obj->count; i++) {
        if (obj->seats[i] == p) {
            idx = i;
            break;
        }
    }

    if (idx != -1) {
        for (int i = idx; i < obj->count - 1; i++) {
            obj->seats[i] = obj->seats[i + 1];
        }
        obj->count--;
    }
}

void examRoomFree(ExamRoom* obj) {
    free(obj->seats);
    free(obj);
}