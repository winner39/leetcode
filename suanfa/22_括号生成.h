#pragma once
#include "dependencies.h"
class Solution { //16:41
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string q = "";
        cal_result(result, q, 0, 0, n);
        return result;
    }
    void cal_result(vector<string> &result, string &temp, int cur_left, int cur_right, int n) {
        if (cur_right == n) {
            result.push_back(temp);
            return;
        }
        else {
            if (cur_left < n) {
                temp.push_back('(');
                cal_result(result, temp, cur_left + 1, cur_right, n);
                temp.pop_back();
            }
            if (cur_right < cur_left) {
                temp.push_back(')');
                cal_result(result, temp, cur_left, cur_right + 1, n);
                temp.pop_back();
            }
        }
    }
};
void test() {
    Solution solution = {};
    vector<string> result = solution.generateParenthesis(3);
}