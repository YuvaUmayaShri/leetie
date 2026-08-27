// ──────────────────────────────────────────────────
// Problem  : 1117. Building H2O
// Difficulty: Medium
// Tags     : Concurrency
// Link     : https://leetcode.com/problems/building-h2o/
// Runtime  : 4 ms (beats 65%)
// Memory   : 11768000 (beats 90%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <mutex>
#include <condition_variable>
#include <functional>

class H2O {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int h_count = 0;

public:
    H2O() {}

    void hydrogen(std::function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return h_count < 2; });
        
        releaseHydrogen();
        
        h_count++;
        cv.notify_all();
    }

    void oxygen(std::function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return h_count == 2; });
        
        releaseOxygen();
        
        h_count = 0;
        cv.notify_all();
    }
};