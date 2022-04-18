#pragma once
#include "dependencies.h"
class MyStack {
public:
    queue<int> a;
    MyStack() {
        
    }

    void push(int x) {
        a.push(x);
    }

    int pop() {
        queue<int> temp = a;
        queue<int> b;
        while (temp.size() > 1) {
            b.push(temp.front());
            temp.pop();
        }
        a = b;
        return temp.back();
    }

    int top() {
        return a.back();
    }

    bool empty() {
        return a.empty();
    }
};