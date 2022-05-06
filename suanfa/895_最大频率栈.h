#pragma once
#include "dependencies.h"
class FreqStack {//9:18
public:
    unordered_map<int, int> infoIndex;
    unordered_map<int, stack<int>> infoP;
    int maxP;
    FreqStack() {
        maxP = 1;
    }

    void push(int val) {
        if (infoIndex.find(val) == infoIndex.end()) {
            infoP[1].push(val);
            infoIndex[val] = 1;
        }
        else {
            int temp = ++infoIndex[val];
            infoP[temp].push(val);
            if (temp > maxP) {
                maxP++;
            }
        }
    }

    int pop() {
        int result = infoP[maxP].top();
        if (--infoIndex[result] == 0) {
            infoIndex.erase(result);
        }    
        infoP[maxP].pop();
        if (infoP[maxP].empty()) {
            maxP--;
        }
        return result;
    }
};