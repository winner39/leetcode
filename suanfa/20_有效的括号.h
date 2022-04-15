#pragma once
#include "dependencies.h"
class Solution {
public:
    bool isValid(string s) {
        stack<char> loginfo;
        for (auto i : s) {
            switch (i) {
            case ')':
                if (!loginfo.empty() && loginfo.top() == '(') {
                    loginfo.pop();
                }
                else return false;
                break;
            case ']':
                if (!loginfo.empty() && loginfo.top() == '[') {
                    loginfo.pop();
                }
                else return false;
                break;
            case '}':
                if (!loginfo.empty() && loginfo.top() == '{') {
                    loginfo.pop();
                }
                else return false;
                break;
            default:
                loginfo.push(i);
                break;
            }
        }
        if (loginfo.empty()) return true;
        return false;
    }
};