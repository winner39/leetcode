#pragma once
#include "dependencies.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            int j = i;
            while (++j < nums.size() && nums[j] == nums[i]);
            if (i != j - 1) {
                nums.erase(nums.begin() + i + 1, nums.begin() + j);
            }
        }
        return nums.size();
    }
};
void test() {
    Solution solution = {};
    vector<int> temp = { 1,1 };
    cout << solution.removeDuplicates(temp);
}