// ──────────────────────────────────────────────────
// Problem  : 630. Course Schedule III
// Difficulty: Hard
// Tags     : Array, Greedy, Sorting, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/course-schedule-iii/
// Runtime  : 14 ms (beats 100%)
// Memory   : 20952000 (beats 53%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int compare(const void* a, const void* b) {
    int* courseA = *(int**)a;
    int* courseB = *(int**)b;
    return courseA[1] - courseB[1];
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void maxHeapifyDown(int* heap, int size, int index) {
    while (2 * index + 1 < size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(&heap[index], &heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

void push(int* heap, int* size, int val) {
    heap[*size] = val;
    (*size)++;
    maxHeapifyUp(heap, *size - 1);
}

int pop(int* heap, int* size) {
    int top = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    maxHeapifyDown(heap, *size, 0);
    return top;
}

int scheduleCourse(int** courses, int coursesSize, int* coursesColSize) {
    qsort(courses, coursesSize, sizeof(int*), compare);

    int* heap = (int*)malloc(coursesSize * sizeof(int));
    int heapSize = 0;
    int time = 0;

    for (int i = 0; i < coursesSize; i++) {
        int duration = courses[i][0];
        int lastDay = courses[i][1];

        if (time + duration <= lastDay) {
            time += duration;
            push(heap, &heapSize, duration);
        } else if (heapSize > 0 && heap[0] > duration) {
            time += duration - pop(heap, &heapSize);
            push(heap, &heapSize, duration);
        }
    }

    free(heap);
    return heapSize;
}