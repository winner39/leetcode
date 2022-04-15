#pragma once
#include "dependencies.h"
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> loginfo;
        for (auto i : s) {
            if (i == ')') {
                if (!loginfo.empty() && loginfo.top() == '(')
                    loginfo.pop();
                else {
                    loginfo.push(i);
                }
            }
            else {
                loginfo.push(i);
            }
        }
        return loginfo.size();
    }
};