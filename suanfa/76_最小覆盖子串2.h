#pragma once
#include"dependencies.h"
class Solution {
public:
    string minWindow(string s, string t) {
        deque<int> count(128, 1e6);
        deque<int> cur_count(128);
        int left = -1, right = 0, best_left = 0;
        int minWindow = 1e6;
        bool ischecked = false;
        for (int i = 0; i < t.size(); i++) {
            if (count[t[i]] == 1e6) {
                count[t[i]] = 1;
            }
            else {
                count[t[i]]++;
            }
        }
        while (++left < s.size() && count[s[left]] == 1e6);
        best_left = left;
        for (int i = left; i < s.size(); i++) {
            cur_count[s[i]]++;
            if (i - left >= minWindow) {
                if (--cur_count[s[left]] < count[s[left]]) ischecked = false;
                while (++left<s.size()&&count[s[left]] == 1e6);
            }
            if (cur_count[s[i]] > count[s[i]]) {
                int j = left;
                for (; s[j] != s[i]; j++) {
                    if (count[s[j]] != 1e6) {
                        if (cur_count[s[j]] - 1 < count[s[j]]) break;
                        cur_count[s[j]]--;
                    }
                }
                if (s[j] == s[i]) {
                    cur_count[s[j++]]--;
                    for (; s[j] != s[i]; j++) {
                        if (count[s[j]] != 1e6) {
                            if (cur_count[s[j]] - 1 < count[s[j]]) break;
                            cur_count[s[j]]--;
                        }
                    }
                }
                left = j;
            }
            if (i - left < minWindow && (ischecked || all_correct(count, cur_count))) {
                minWindow = i - left;
                best_left = left;
                right = i;
                ischecked = true;
            }
        }
        if (minWindow == 1e6) {
            return "";
        }
        return s.substr(best_left, minWindow + 1);
    }
    bool all_correct(deque<int>& count, deque<int>& cur_count) {
        for (int i = 0; i < 128; i++) {
            if (count[i] != 1e6 && count[i] > cur_count[i]) return false;
        }
        return true;
    }
};
void test() {
    Solution solution = {  };
    cout << solution.minWindow("acbdbaab","aabd");
}