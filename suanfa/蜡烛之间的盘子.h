#pragma once
#include "dependencies.h"
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<vector<int> >::iterator i_;
        vector<int> help;
        vector<int> result;
        bool sb = false;
        int pos_left = -1, pos_right = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '|') {
                help.push_back(i);
            }
        }
        if (help.size() <= 1) {
            sb = true;
        }
        if (!sb) {
            for (i_ = queries.begin(); i_ < queries.end(); i_++) {
                int temp1 = binary_search(help, (*i_)[0], 0, help.size()-1, true);
                int temp2 = binary_search(help, (*i_)[1], 0, help.size()-1, false);
                int pos_left = help[temp1], pos_right = help[temp2];
                if (pos_left < pos_right && pos_left >=(*i_)[0] && pos_right <= (*i_)[1]) {
                    result.push_back(pos_right - pos_left + 1 - (temp2 - temp1 + 1));
                }
                else {
                    result.push_back(0);
                }
            }
        }
        else {
            for (i_ = queries.begin(); i_ < queries.end(); i_++) {
                result.push_back(0);
            }
        }
        return result;
    }
    int binary_search(vector<int> &help,int target,int left,int right,bool bigger) {
        int mid = left + (right - left) / 2;
        if (help[mid] == target) {
            return mid;
        }
        else if (left == right) {
            if (bigger) {
                if (help[left] > target) {
                    return left;
                }
                else {
                    if (left + 1 < help.size()) {
                        return left + 1;
                    }
                    else {
                        return left;
                    }
                }
            }
            else {
                if (help[left] < target) {
                    return left;
                }
                else {
                    if (left != 0) {
                        return left - 1;
                    }
                    else {
                        return 0;
                    }
                }
            }
            return left;
        }
        else if (help[mid] > target) {
            return binary_search(help, target, left, mid, bigger);
        }
        else {
            return binary_search(help, target, mid + 1, right, bigger);
        }
    }
};
void test() {
    
    Solution solution = {};
    vector<vector<int> > queries;
    queries.push_back(vector<int>{2,5});
    queries.push_back(vector<int>{5,9});
    solution.platesBetweenCandles("**|**|***|", queries );
}