#pragma once
#include "dependencies.h"
class NumArray {
public:
    vector<int> memory;
    NumArray(vector<int>& nums) {
        memory.reserve(nums.size());
        int total = 0;
        for (int i = 0; i < nums.size();i++) {
            total += nums[i];
            memory[i] = total;
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) return memory[right];
        return memory[right] - memory[left - 1];
    }
};