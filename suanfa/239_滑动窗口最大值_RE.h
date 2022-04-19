#pragma once
#include"dependencies.h"
class Solution {//20:08~20:16
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		deque<int> memory;
		for (int i = 0; i < k; i++) {
			while (!memory.empty() && nums[memory.back()] < nums[i]) {
				memory.pop_back();
			}
			memory.push_back(i);
		}
		result.push_back(nums[memory.front()]);
		for (int i = k; i < nums.size(); i++) {
			if (memory.front() == i - k) {
				memory.pop_front();
			}
			while (!memory.empty() && nums[memory.back()] < nums[i]) {
				memory.pop_back();
			}
			memory.push_back(i);
			result.push_back(nums[memory.front()]);
		}
		return result;
	}
};