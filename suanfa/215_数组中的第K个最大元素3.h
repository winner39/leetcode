#pragma once
#include "dependencies.h"
class Solution {//10:25
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> q;
        for (auto i : nums) {
            q.push(i);
        }
        int result = 0;
        for (int i = 0; i < k; i++) {
            result = q.top();
            q.pop();
        }
        return result;
    }
};
void test() {
    Solution solution = {};
    vector<int> ask = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    cout << solution.findKthLargest(ask, 4) << endl;
}