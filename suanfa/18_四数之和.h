#pragma once
#include "dependencies.h"
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        int goal = 0;
        sort(nums.begin(), nums.end());
        if (nums.size() < 4) {
            return result;
        }
        result.reserve(nums.size() - 3);
        for (int i = 0; i < n; i++) {
            if (nums[i] > target / 4) break;
            if (i == 0 || nums[i] != nums[i - 1]) {
                goal = target - nums[i];
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] > goal / 3) break;
                    if (j == i + 1 || nums[j] != nums[j - 1]) {
                        goal -= nums[j];
                        int l = n - 1;
                        for (int k = j + 1; k < n; k++) {
                            if (k == j + 1 || nums[k] != nums[k - 1]) {
                                if (k >= l) break;
                                while (l > k && nums[k] + nums[l] > goal) l--;
                                if (k >= l) break;
                                if (nums[k] + nums[l] == goal)
                                    result.push_back({ nums[i],nums[j],nums[k],nums[l] });
                            }
                        }
                        goal += nums[j];
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
    vector<int> input = { 1, 0, -1, 0, -2, 2 };
    vector<vector<int>> result = solution.fourSum(input, 0);
    for (auto i : result) {
        for_each(i.begin(), i.end(), printint);
        cout << endl;
    }
}