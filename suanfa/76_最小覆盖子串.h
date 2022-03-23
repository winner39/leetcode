#pragma once
#include"dependencies.h"
class Solution {
public:
    string minWindow(string s, string t) {
        deque<int> count(128,1e6);
        deque<int> cur_count(128);
        deque<deque<int>> log_pos(128);
        int left = -1, right = 0, best_left = 0;
        int minWindow = 1e6;
        for (int i = 0; i < t.size(); i++) {
            if (count[t[i]] == 1e6) {
                count[t[i]] = 1;
            }
            else {
                count[t[i]]++;
            }
        }
        while (++left<s.size()&&count[s[left]] == 1e6);
        best_left = left;
        for (int i = left; i < s.size(); i++) {
            //cout << s.substr(left, i - left + 1) << endl;
            if (count[s[i]] != 1e6) {
                log_pos[s[i]].push_back(i);
            }
            if (++cur_count[s[i]] > count[s[i]]) {
                int j = left;
                int end = log_pos[s[i]][1];
                for (; j < end; j++) {
                    if (count[s[j]] != 1e6) {
                        if (cur_count[s[j]] - 1 < count[s[j]]) break;
                        log_pos[s[j]].pop_front();
                        cur_count[s[j]]--;
                    }
                }
                left = j;
                //cout << s.substr(left, i - left + 1) << endl;
            }
            if (all_correct(count,cur_count) && i - left < minWindow) {
                minWindow = i - left;
                best_left = left;
                right = i;
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
    cout<<solution.minWindow("ab", "a");
}