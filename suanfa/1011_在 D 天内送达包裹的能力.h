#pragma once
#include "dependencies.h"
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int boundary = *(max_element(weights.begin(), weights.end()));
        int min_w = boundary;
        while (cal_days(weights, min_w) > days) {
            min_w *= 2;
        }
        return binary_search_smaller(weights, days, max(boundary,min_w / 2), min_w);
    }
    int binary_search_smaller(vector<int>& weights, int target, int left, int right) {
        int mid = left + (right - left)/2;
        if (left == right) {
            if (cal_days(weights, left) > target) {
                return left + 1;
            }
            return left;
        }
        else if (cal_days(weights, mid) > target) {
            return binary_search_smaller(weights, target, mid + 1, right);
        }
        else {
            return binary_search_smaller(weights, target, left, mid);
        }
    }
    int cal_days(vector<int> weights, int w) {
        int day = 1;
        int cur_w = w;
        for (int i = 0; i < weights.size(); i++) {
            cur_w -= weights[i];
            if (cur_w < 0) {
                cur_w = w - weights[i];
                day++;
            }
        }
        return day;
    }
}; 
void test() {
    Solution solution = {};
    vector<int> ask = { 1, 2, 3, 1, 1 };
    solution.shipWithinDays(ask, 4);
}