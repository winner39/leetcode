#pragma once
#include "dependencies.h"
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int max = -1e5, secondary_max = -1e5;
        int left = 0;
        vector<int> result;
        for (int i = left; i < left + k; i++) {
            if (nums[i] >= max) max = nums[i], secondary_max = max;
            else if (nums[i] > secondary_max) secondary_max = nums[i];
        }
        result.push_back(max);
        for (int i = k; i < nums.size(); i++) {
            if (nums[i - k] == max) max = secondary_max;
            if (nums[i] >= max) max = nums[i], secondary_max = max;
            else if (nums[i] > secondary_max) secondary_max = nums[i];
            result.push_back(max);
        }
        return result;
    }
};