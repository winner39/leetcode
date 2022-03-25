#pragma once
#include "dependencies.h"
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> need(26,0);
        for (const char& c : s1) {
            need[c-'a']++;
        }
        int count = 0;
        for (const int i : need) {
            if (i != 0) count++;
        }
        int left = 0;
        if (s1.size() > s2.size()) return false;
        for (int i = 0; i < s1.size() - 1; i++) {
            if(--need[s2[i]-'a'] == 0) count--;
        }
        for (int i = s1.size() - 1; i < s2.size(); i++) {
            if (--need[s2[i] - 'a'] == 0) count--;
            if (count == 0) return true;
            if (need[s2[left++] - 'a']++ == 0) count++;
        }
        return false;
    }
};
void test() {
    Solution solution = {};
    cout << solution.checkInclusion("horse",
        "ros");
}