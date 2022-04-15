#pragma once
#include "dependencies.h"
class Solution {
public:
    int minInsertions(string s) {
        int result = 0;
        int left = 0, right = 0;
        for (auto i : s) {
            if (i == '(') {
                if (right == 1) {
                    if (left > 0) {
                        result++;
                        left--;
                    }
                    else {
                        result += 2;
                    }
                    right = 0;
                }
                left++;
            }
            else {
                right++;
                if (right == 2) {
                    if (left > 0) {
                        left--;
                    }
                    else {
                        result++;
                    }
                    right = 0;
                }
            }
        }
        if (right == 1 && left == 0) result += 2;
        else if (right == 1 && left > 0) left--, result += 1;
        result += left * 2;
        return result;
    }
};
void test() {
    string s = ")())()";
    Solution solution = {};
    cout<<solution.minInsertions(s)<<endl;
}