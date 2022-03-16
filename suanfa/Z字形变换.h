#pragma once
#include "dependencies.h"
class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        int span = 0;
        if (numRows == 1) {
            return s;
        }
        for (int i = 0; i < numRows; i++) {
            int span = (numRows-1-i)*2;
            int temp = (numRows-1)*2 - span;
            int j = i;
            if (j >= s.size()) {
                break;
            }
            result += s[j];
            while (true) {
                j += span;
                if (span != 0) {
                    if (j >= s.size()) {
                        break;
                    }
                    result += s[j];
                    
                }
                j += temp;
                if (temp != 0) {
                    if (j >= s.size()) {
                        break;
                    }
                    result += s[j];
                }
            }
        }
        cout << result << endl;
        return result;
    }
};
void test() {
    string a = "A";
    Solution solution = {};
    solution.convert(a, 1);
}