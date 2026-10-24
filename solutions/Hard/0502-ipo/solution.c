// ──────────────────────────────────────────────────
// Problem  : 502. IPO
// Difficulty: Hard
// Tags     : Array, Greedy, Sorting, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/ipo/
// Runtime  : 67 ms (beats 37%)
// Memory   : 28180000 (beats 77%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

typedef struct {
    int profit;
    int capital;
} Project;

int compareProjects(const void* a, const void* b) {
    return ((Project*)a)->capital - ((Project*)b)->capital;
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
    Project* projects = (Project*)malloc(profitsSize * sizeof(Project));
    for (int i = 0; i < profitsSize; i++) {
        projects[i].profit = profits[i];
        projects[i].capital = capital[i];
    }
    
    qsort(projects, profitsSize, sizeof(Project), compareProjects);
    
    int* maxHeap = (int*)malloc(profitsSize * sizeof(int));
    int heapSize = 0;
    
    void push(int val) {
        int curr = heapSize++;
        maxHeap[curr] = val;
        while (curr > 0) {
            int parent = (curr - 1) / 2;
            if (maxHeap[parent] < maxHeap[curr]) {
                int temp = maxHeap[parent];
                maxHeap[parent] = maxHeap[curr];
                maxHeap[curr] = temp;
                curr = parent;
            } else {
                break;
            }
        }
    }
    
    int pop() {
        int res = maxHeap[0];
        maxHeap[0] = maxHeap[--heapSize];
        int curr = 0;
        while (2 * curr + 1 < heapSize) {
            int left = 2 * curr + 1;
            int right = 2 * curr + 2;
            int largest = curr;
            
            if (left < heapSize && maxHeap[left] > maxHeap[largest]) {
                largest = left;
            }
            if (right < heapSize && maxHeap[right] > maxHeap[largest]) {
                largest = right;
            }
            if (largest != curr) {
                int temp = maxHeap[curr];
                maxHeap[curr] = maxHeap[largest];
                maxHeap[largest] = temp;
                curr = largest;
            } else {
                break;
            }
        }
        return res;
    }
    
    int i = 0;
    for (int j = 0; j < k; j++) {
        while (i < profitsSize && projects[i].capital <= w) {
            push(projects[i].profit);
            i++;
        }
        
        if (heapSize == 0) {
            break;
        }
        
        w += pop();
    }
    
    free(projects);
    free(maxHeap);
    
    return w;
}