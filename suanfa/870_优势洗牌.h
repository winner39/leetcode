#pragma once
#include "dependencies.h"
class Solution {//15:13
public:
    class NumsAndIndex {
    public:
        int value;
        int index;
        NumsAndIndex(int a,int b):value(a),index(b){}
    };
    static bool upper(NumsAndIndex& a, NumsAndIndex& b) {
        return a.value <= b.value;
    }
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        vector<NumsAndIndex> nums_opponent;
        nums_opponent.reserve(nums2.size());
        for (int i = 0; i < nums2.size(); i++) {
            nums_opponent.emplace_back(nums2[i], i);
        }
        sort(nums_opponent.begin(), nums_opponent.end(), upper);
        int left = 0, i = 0;
        vector<int> result(nums1.size(), 0);
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] > nums_opponent[left].value) {
                swap(nums1[i], nums1[left++]);
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            result[nums_opponent[i].index] = nums1[i];
        }
        return result;
    }
    /*void quick_sort(vector<int>& nums, int left, int right) {
        int base = nums[left];
        int i = left;
        int j = right + 1;
        if (left < right) {
            while (true) {
                while (++i < j && nums[i] <= base);
                while (--j > i && nums[j] > base);
                if (i >= j) {
                    if (i <= right) {
                        swap(nums[left], nums[i]);
                        quick_sort(nums, left, i);
                        quick_sort(nums, i, right);
                    }
                    else {
                        swap(nums[left], nums[right]);
                        quick_sort(nums, left, right - 1);
                    }
                    break;
                }
                else {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }*/
};
void printint(int i) {
    cout << i << ",";
}
void test() {
    Solution solution = {};
    vector<int> nums1 = { 2, 7, 11, 15 };
    vector<int> nums2 = { 1, 10, 4, 11 };
    vector<int> result = solution.advantageCount(nums1, nums2);
    for_each(result.begin(), result.end(), printint);
}