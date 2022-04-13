#pragma once
#include "dependencies.h"
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> temp;
        temp[0]++;
        int total = 0, result = 0;
        for (auto i : nums) {
            total += i;
            if (temp.find(total - k) != temp.end()) {//find貌似比单纯检验该下标为0的速度快
                result += temp[total - k];
            }
            temp[total]++;
        }
        return result;
    }
};