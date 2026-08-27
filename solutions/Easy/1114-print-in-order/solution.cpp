// ──────────────────────────────────────────────────
// Problem  : 1114. Print in Order
// Difficulty: Easy
// Tags     : Concurrency
// Link     : https://leetcode.com/problems/print-in-order/
// Runtime  : 9 ms (beats 36%)
// Memory   : 9584000 (beats 46%)
// Language : cpp
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <mutex>
#include <condition_variable>
#include <functional>

class Foo {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int step = 1;

public:
    Foo() {}

    void first(std::function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(mtx);
        
        printFirst();
        
        step = 2;
        cv.notify_all();
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return step == 2; });
        
        printSecond();
        
        step = 3;
        cv.notify_all();
    }

    void third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return step == 3; });
        
        printThird();
    }
};