#pragma once
#include "dependencies.h"
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() > 0) {
            int index = binary_search(nums, target, 0, nums.size() - 1, 0);
            cout << index << endl;
            if (index != -1) {
                int index_left = binary_search(nums, target, 0, nums.size() - 1, -1);
                int index_right = binary_search(nums, target, 0, nums.size() - 1, 1);
                int result_left = -1, result_right = -1;
                if (nums[index_left] == target) result_left = index_left;
                else result_left = index_left + 1;
                if (nums[index_right] == target) result_right = index_right;
                else result_right = index_right - 1;
                return { result_left,result_right };
            }
        }
        return { -1,-1 };
    }
    int binary_search(vector<int>& nums, int target, int left, int right,int boundary_mode) {//根据boundary_mode决定查找的是左边界还是右边界还是单纯的查找
        int mid = left + (right - left) / 2;
        if (nums[mid] == target&& left != right) {
            if (boundary_mode == -1) {
                return binary_search(nums, target, left, mid, boundary_mode);
            }
            else if(boundary_mode == 1){
                return binary_search(nums, target, mid + 1, right, boundary_mode);
            }
            else {
                return mid;
            }
        }
        else if (left == right) {
            if (boundary_mode == 0) {
                if (nums[left] != target) { return -1; }
            }
            return left;
        }
        else if (nums[mid] > target) {
            return binary_search(nums, target, left, mid, boundary_mode);
        }
        else {
            return binary_search(nums, target, mid + 1, right, boundary_mode);
        }
    }
};
void test() {
    Solution solution = {};
    vector<int> test = { 1 };
    solution.searchRange(test, 1);
}