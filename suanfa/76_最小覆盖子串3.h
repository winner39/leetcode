#pragma once
#include"dependencies.h"
class Solution {
public:
    string minWindow(string s, string t) {//使用isok辅助判断是否完全符合
        unordered_map<char, int> count;
        int isok = 0;
        int left = 0, best_left = 0;
        int minWindow = 1e6;
        for (int i = 0; i < t.size(); i++) {
            count[t[i]]++;
        }
        isok = count.size();
        for (int i = 0; i < s.size(); i++) {
            if (count.find(s[i]) != count.end()) {
                if (--count[s[i]] == 0) {
                    isok--;
                }
            }
            if (isok == 0) {
                while (true) {
                    if (count.find(s[left]) != count.end()) {
                        if (count[s[left]] + 1 <= 0)
                            count[s[left]]++;
                        else
                            break;
                    }
                    left++;
                }
                if (i - left < minWindow) {
                    best_left = left;
                    minWindow = i - left;
                }
                count[s[left]]++;
                left++;
                isok++;
            }
        }
        if (minWindow == 1e6) {
            return "";
        }
        return s.substr(best_left, minWindow + 1);
    }
};
void test() {
    Solution solution = {  };
    cout << solution.minWindow("acbdbaab", "aabd");
}