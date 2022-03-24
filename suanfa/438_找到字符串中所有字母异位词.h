#pragma once
#include "dependencies.h"
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> ori_count;
        for (const char& c : p) {
            ori_count[c]++;
        }
        unordered_map<char, int> count = ori_count;
        vector<int> answer;
        int isok = count.size();
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (count.find(s[i]) == count.end()) {
                left = i + 1;
                count = ori_count;
                isok = count.size();
            }
            else if (i - left + 1 < p.size()) {
                count[s[i]]--;
                if(count[s[i]]==0 )isok--;
            }
            else {

            }
        }
        return answer;
    }
};
void test() {
    Solution solution = {};
    solution.findAnagrams("vwwvv"
        ,"vwv");
}