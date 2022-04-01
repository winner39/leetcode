#pragma once
#include "dependencies.h"
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (k == 0)return {};
		vector<int>res;
		deque<size_t>window;//该队列具有以下特性，1、下标对应的值递减 2、window中越靠前的下标越在nums的前端，且必在窗口中
		//换句话说，如果存在比window前排小的值存在window中，那其必然在nums的相对靠后位置
		/*Init K integers in the list*/
		for (size_t i = 0; i < k; i++) {
			while (!window.empty() && nums[i] > nums[window.back()]) {
				window.pop_back();
			}
			window.push_back(i);
		}
		res.push_back(nums[window.front()]);
		/*End of initialization*/
		for (size_t i = k; i < nums.size(); i++) {
			/*剔除队头时，仅需考虑队头是否是该值，因为该队列越靠后的值越在滑动窗口后端，不可能被一并剔除，此外，如若不是该值，则不影响结果，
			不需要对队列进行改变，*/
			if (!window.empty() && window.front() == i - k) {
				window.pop_front();
			}
			while (!window.empty() && nums[i] > nums[window.back()]) {//把所有小于新增数字的值从队尾开始一一剔除，因为被剔除的值必然在滑动窗口偏后的位置，因此这样的剔除方式没有心理负担
				window.pop_back();
			}
			window.push_back(i);
			res.push_back(nums[window.front()]);
		}
		return res;
	}
};
void test() {
    Solution solution = {}; 
    vector<int> nums = { 9, 10, 9, -7, -4, -8, 2, -6 };
    solution.maxSlidingWindow(nums, 5);
}
