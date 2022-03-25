#pragma once
#include "dependencies.h"
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> ori_need;
        for (const char& c : s1) {
            ori_need[c]++;
        }
        unordered_map<char, int> need = ori_need;
        int left = 0,not_match = need.size();
        for (int i = 0; i < s2.size(); i++) {
            if (need.find(s2[i]) == need.end()) {
                left = i + 1;
                need = ori_need;
                not_match = ori_need.size();
            }
            else {
                need[s2[i]]--;
                if (need[s2[i]] < 0) {
                    while (s2[left] != s2[i]) {
                        if (need[s2[left++]]++ == 0) not_match++;
                    }
                    need[s2[left++]]++;
                }
                else if (need[s2[i]] == 0) {
                    not_match--;
                }
                if (not_match == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};
void test() {
    Solution solution = {};
    cout<<solution.checkInclusion("hello",
        "ooolleoooleh");
}