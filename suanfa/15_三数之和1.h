#pragma once
#include "dependencies.h"
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {//双指针做法
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        if (nums.size() <= 2) {
            return result;
        }
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) break;
            if (i == 0 || nums[i] != nums[i - 1]) {//保证第一个数不重复
                int k = n - 1;
                for (int j = i + 1; j < n; j++) {
                    if (k <= j) break;//没救了
                    if (j == i + 1 || nums[j] != nums[j - 1]) {//保证第二个数不重复
                        int temp = nums[i] + nums[j];
                        while (k > j && temp + nums[k] > 0) { k--; }
                        if (k <= j) break;//没救了
                        if (temp + nums[k] == 0) result.push_back({ nums[i],nums[j],nums[k] });
                    }
                }
            }
        }
        return result;
    }
};
void printint(int& i) {
    cout << i << ",";
}
void test() {
    Solution solution = {};
    vector<int> input = { -1,0,1,2,-1,-4 };
    vector<vector<int>> result = solution.threeSum(input);
    for (auto i : result) {
        for_each(i.begin(), i.end(), printint);
        cout << endl;
    }
}