#pragma once
#include "dependencies.h"
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size();i++) {
            if (nums[i] == 0) {
                int j = i;
                while (++j < nums.size() && nums[j] == 0);
                if (j == nums.size()) break;
                swap(nums[i], nums[j]);
            }
        }
    }
};