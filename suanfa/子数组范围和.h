#pragma once
#include "dependencies.h"
class log_ {
public:
    int value;
    int Frequency;
    log_(int val, int fre) :value(val), Frequency(fre) {}
};
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long result = 0;
        sort(nums.begin(),nums.end());
        vector<int>::iterator i = nums.begin();
        vector<log_> nums_frequency;
        int fre = 1, val = *i;
        for (i = nums.begin(); i < nums.end()-1; i++) {
            if (val < *(i + 1)) {
                nums_frequency.emplace_back(val,fre);
                fre = 1;
                val = *(i + 1);
            }
            else {
                fre++;
            }
        }
        nums_frequency.emplace_back(val, fre);
        vector<log_>::iterator f_i_left = nums_frequency.begin(), f_i_right = nums_frequency.begin();
        for (; f_i_left < nums_frequency.end(); f_i_left++) {
            for (f_i_right = f_i_left + 1; f_i_right < nums_frequency.end(); f_i_right++) {
                result += (*f_i_left).Frequency * (*f_i_right).Frequency * ((*f_i_right).value - (*f_i_left).value);
            }
        }
        cout << result << endl;
        return result;
    }
};
void test() {
    vector<int> nums = { -3,-2,1,4,4 };
    Solution solution = {};
    solution.subArrayRanges(nums);
}