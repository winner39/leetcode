#pragma once
#include "dependencies.h"
class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int, vector<int>, less<int>> maxheap;
    unordered_map<int, pair<int, int>> loginfo;
    int garbage_left = 0, garbage_right = 0;

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {//����˼�룺��Ϊ���޷�ɾ���ǶѶ�Ԫ�أ�����ֻҪ��ɾ����Ԫ�ز�Ӱ���ж���λ��ʱ����ס��ռ�Ŀӣ������������ά�������С��ƽ��
        vector<double> result;
        for (int i = 0; i < k; i++) {
            push_queue(nums[i]);
        }
        result.push_back(get_middle(k));
        for (int i = k; i < nums.size(); i++) {
            if (nums[i - k] >= minheap.top()) {//���ܻ�����ظ���������Ҫɾ��������ʵλ����һ����������������ɾ�����������С�ѵĶѶ�����ʵ����ƽ��󶼻�õ�ͬһ���
                loginfo[nums[i - k]].second++;
                garbage_right++;
            }
            else {
                loginfo[nums[i - k]].first++;
                garbage_left++;
            }
            //while (delete_queue()) {//���п��ޣ���Ϊ�ڽ�����һ��ѭ��ǰ�����С���Ѿ���ƽ��״̬�����ǽ�1��garbage������£�����֮���size����2��push��size����3������һ��balance����ƽ�⵽��1
            //    balance_queue();
            //}
            push_queue(nums[i]);//��˸��������ע�ͣ���ʱpush�������ѱ�ƽ��
            while (delete_queue()) {
                //balance_queue();//�����򴫵�������ʱ����Ҫ��ʱ����,����ʵ����Ҫ����Ϊɾ�Ķ���������������Ӱ�������ѵ�ƽ��
            }
            result.push_back(get_middle(k));
        }
        return result;
    }
    void push_queue(int num) {
        if (minheap.empty() || minheap.top() <= num) minheap.push(num);
        else maxheap.push(num);
        balance_queue();
    }
    void balance_queue() {//���������ڶѶ�����Ӱ�쵽�ж���λ��ʱ��ֻҪ��ס�����С�ѵ��������������������������ά��ƽ���Ҳ�Ӱ����λ��ƽ��
        if (minheap.size() - garbage_right > maxheap.size() - garbage_left + 1) {
            if (loginfo[minheap.top()].second > 0) {//�����򴫵�������ʱ����Ҫ��ʱ����,����ʵ����Ҫ����Ϊɾ�Ķ���������������Ӱ�������ѵ�ƽ��
                //��������push��Ҳ����ʹ�ڶѶ���������Ҫת�ƣ��Լ���������ۣ������ڶѶ���4���������������������С�ѵĶѶ���2�֣�*��һ��push��Ԫ�س��������ѻ�����С�ѣ�2�֣�
                loginfo[minheap.top()].second--;
                loginfo[maxheap.top()].first++;
            }
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else if (maxheap.size() - garbage_left > minheap.size() - garbage_right) {
            if (loginfo[maxheap.top()].first > 0) {
                loginfo[minheap.top()].first--;
                loginfo[maxheap.top()].second++;
            }
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    bool delete_queue() {//��ͣ��ɾ��λ��ջ��������
        if (!maxheap.empty() && loginfo[maxheap.top()].first > 0) {
            loginfo[maxheap.top()].first--;
            garbage_left--;
            maxheap.pop();
            return true;
        }
        else if (!minheap.empty() && loginfo[minheap.top()].second > 0) {
            loginfo[minheap.top()].second--;
            garbage_right--;
            minheap.pop();
            return true;
        }
        return false;
    }
    double get_middle(int k) {
        if (k & 1) {
            return minheap.top();
        }
        else {
            return ((double)minheap.top() + (double)maxheap.top()) / 2;
        }
    }
};   

void test() {
    Solution solution = {};
    /*vector<int> ask = { 9, 7, 0, 3, 9, 8, 6, 5, 7, 6 };
    vector<double> result = solution.medianSlidingWindow(ask, 2);*/
    /*vector<int> ask = { 4, 1, 3, 7, 2, 5, 6 };
    vector<double> result = solution.medianSlidingWindow(ask, 5);*/
    vector<int> ask = { 3,4,5,6,2 };
    vector<double> result = solution.medianSlidingWindow(ask, 4);
    for_each(result.begin(), result.end(), [](const double& x) {cout << x << ","; }); 
}