#pragma once
#include "dependencies.h"
class MyQueue {
public:
    stack<int> a;
    MyQueue() {

    }

    void push(int x) {
        a.push(x);
    }

    int pop() {
        stack<int> tempstack;
        while (a.size() > 1) {
            tempstack.push(a.top());
            a.pop();
        }
        int result = a.top();
        a.pop();
        while (!tempstack.empty()) {
            a.push(tempstack.top());
            tempstack.pop();
        }
        return result;
    }

    int peek() {
        stack<int> tempstack = a;
        while (tempstack.size() > 1) {
            tempstack.pop();
        }
        return tempstack.top();
    }

    bool empty() {
        return a.empty();
    }
};