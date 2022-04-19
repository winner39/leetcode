#pragma once
#include "dependencies.h"
class Solution {//20:30
public:
    int findKthLargest(vector<int>& nums, int k) {
        return fastsort(nums, 0, nums.size(), k);
    }
    int fastsort(vector<int>nums, int l, int r, int target) {
        if (l == r) {
            return nums[l];
        }
        int left = l,right = r;
        while (true) {
            while (++left < right && nums[left] > nums[l]);
            while (--right > left && nums[right] < nums[l]);
            if (left >= right) {
                if (left == target) return nums[l];
                if (left == r) {
                    swap(nums[l], nums[r - 1]);
                    return fastsort(nums, l, r - 1, target);
                }
                else {
                    swap(nums[l], nums[left - 1]);
                    if (left > target) {
                        return fastsort(nums, l, left - 1, target);
                    }
                    else {
                        return fastsort(nums, left, r, target);
                    }
                }
            }
            else {
                cout << left << "," << right << endl;
                swap(nums[left], nums[right]);
            }
        }
    }
};
void test() {
    Solution solution = {};
    vector<int> ask = { 2,1 };
    cout << solution.findKthLargest(ask, 1) <<endl;
}