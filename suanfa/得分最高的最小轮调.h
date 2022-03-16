#pragma once
#include "dependencies.h"
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int* die = new int[nums.size()+1];
        memset(die, 0, sizeof(int)*(nums.size()+1));
        int result = 0, max_foot = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i < nums[i]) {
                die[nums.size()-((nums[i]-1) - i)]++;
            }
            else{
                result++;
                if (nums[i] != 0) {
                    die[i - nums[i] + 1]++;
                }
            }
        }
        int max_result = result;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] != 0) {
                result++;
            }
            result -= die[i];
            if (result > max_result) {
                max_foot = i;
                max_result = result;
                
            }
        }
        delete []die;
        return max_foot;
    }
};  
void test() {
    Solution solution = {};
    vector<int> a = { 1,3,0,2,4 };
    /*vector<int> b(a.begin() + 76, a.end());
    for (int i = 0; i < 76; i++) {
        b.push_back(a[i]);
    }*/
    solution.bestRotation(a);
    //54
}