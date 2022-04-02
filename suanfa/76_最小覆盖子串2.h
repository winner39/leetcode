#pragma once
#include"dependencies.h"
class Solution {
public:
    string minWindow(string s, string t) {//强行从头检查只会灰飞烟灭
        unordered_map<char, int> count;
        unordered_map<char, int> cur_count;
        int left = -1, best_left = 0;
        int minWindow = 1e6;
        bool ischecked = false;
        for (int i = 0; i < t.size(); i++) {
            count[t[i]]++;
        }
        while (++left < s.size() && count.find(s[left]) == count.end());
        best_left = left;
        for (int i = left; i < s.size(); i++) {
            if (i - left >= minWindow) {
                if (--cur_count[s[left]] < count[s[left]]) ischecked = false;
                while (++left < s.size()) {
                    if (count.find(s[left]) != count.end()) {
                        if (cur_count[s[left]] - 1 < count[s[left]])
                            break;
                        else{
                            cur_count[s[left]]--;
                        }
                    }
                }
            }
            if (count.find(s[i]) != count.end()) {
                cur_count[s[i]]++;
                if (cur_count[s[i]] > count[s[i]]) {
                    int j = left;
                    while (true) {
                        if (count.find(s[j]) != count.end()) {
                            if (cur_count[s[j]] - 1 < count[s[j]]) {
                                break;
                            }
                            cur_count[s[j]]--;
                        }
                        j++;
                    }
                    left = j;
                }
                if (i - left < minWindow && (ischecked || all_correct(count, cur_count))) {
                    minWindow = i - left;
                    best_left = left;
                    ischecked = true;
                }
            }
        }
        if (minWindow == 1e6) {
            return "";
        }
        return s.substr(best_left, minWindow + 1);
    }
    bool all_correct(unordered_map<char,int>& count, unordered_map<char,int>& cur_count) {
        for (auto const &cnt : count) {
            if (cnt.second > cur_count[cnt.first]) return false;
        }
        return true;
    }
};
void test() {
    Solution solution = {  };
    cout << solution.minWindow("acbdbaab","aabd");
}