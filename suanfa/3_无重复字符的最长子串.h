#pragma once
#include "dependencies.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() > 0) {
            int used[128], cur_left = 0, cur_right = 0, result = 0;
            memset(used, -1, 128 * sizeof(int));
            for (int i = 0; i < s.size(); i++) {
                cur_right = i;
                if (used[s[i]] != -1) {
                    cur_left = used[s[i]] + 1 > cur_left ? used[s[i]] + 1: cur_left;
                }
                used[s[i]] = i;
                if (cur_right - cur_left > result) {
                    result = cur_right - cur_left;
                }
            }
            return result + 1;
        }
        else {
            return 0;
        }
    }
};
void test() {
    Solution solution = {};
    cout << solution.lengthOfLongestSubstring("abba");
}