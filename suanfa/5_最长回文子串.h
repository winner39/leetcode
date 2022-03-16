#pragma once
#include "dependencies.h"
class Solution {
public:
    string longestPalindrome(string s) {
        int max_length = -1, left = 0, right = 0;
        vector<vector<int> > log(s.size());
        if (s.size() <= 1) {
            return s;
        }
        log[0].push_back(0);
        for (int i = 1; i < s.size(); i++) {
            for (auto iter = log[i - 1].begin(); iter < log[i - 1].end(); iter++) {
                int temp_pos = *iter - 1;
                if (temp_pos >= 0 && s[temp_pos] == s[i]) {
                    log[i].push_back(temp_pos);
                }
            }
            if (s[i - 1] == s[i]) {
                log[i].push_back(i - 1);
            }
            log[i].push_back(i);
        }
        for (int i = 0; i < s.size(); i++) {
            if (i - log[i][0] > max_length) {
                left = log[i][0];
                right = i;
                max_length = i - log[i][0];
            }
        }
        return s.substr(left, right - left + 1);
    }
};
void test() {
    Solution solution = {};
    cout << solution.longestPalindrome("abc");
}
void printint(int a) {
    cout << a << ",";
}