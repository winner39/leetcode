#pragma once
#include "dependencies.h"
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (k == 0)return {};
		vector<int>res;
		deque<size_t>window;//�ö��о����������ԣ�1���±��Ӧ��ֵ�ݼ� 2��window��Խ��ǰ���±�Խ��nums��ǰ�ˣ��ұ��ڴ�����
		//���仰˵��������ڱ�windowǰ��С��ֵ����window�У������Ȼ��nums����Կ���λ��
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
			/*�޳���ͷʱ�����迼�Ƕ�ͷ�Ƿ��Ǹ�ֵ����Ϊ�ö���Խ�����ֵԽ�ڻ������ں�ˣ������ܱ�һ���޳������⣬�������Ǹ�ֵ����Ӱ������
			����Ҫ�Զ��н��иı䣬*/
			if (!window.empty() && window.front() == i - k) {
				window.pop_front();
			}
			while (!window.empty() && nums[i] > nums[window.back()]) {//������С���������ֵ�ֵ�Ӷ�β��ʼһһ�޳�����Ϊ���޳���ֵ��Ȼ�ڻ�������ƫ���λ�ã�����������޳���ʽû��������
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
