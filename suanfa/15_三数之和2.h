#pragma once
#include "dependencies.h"
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {//¹þÏ£±í×ö·¨
        vector<vector<int>> result;
        unordered_map<int, int> distribution;
        distribution.reserve(nums.size());
        sort(nums.begin(), nums.end());
        for (int i : nums) {
            distribution[i]++;
        }
        if (nums.size() <= 2) {
            return result;
        }
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 && (i == 0 || nums[i] != nums[i - 1])) {
                distribution[nums[i]]--;
                for (int j = i + 1; j < n; j++) {
                    if (j == i + 1 || nums[j] != nums[j - 1]) {
                        distribution[nums[j]]--;
                        if (-(nums[i] + nums[j]) >= nums[j] && distribution[-(nums[i] + nums[j])] != 0) {
                            result.push_back({ nums[i],nums[j],-(nums[i] + nums[j]) });
                        }
                        distribution[nums[j]]++;
                    }
                }
                distribution[nums[i]]++;
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