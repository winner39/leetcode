#pragma once
#include"dependencies.h"
class MedianFinder {//10:31-16:47
public:
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {

    }

    void addNum(int num) {
        if (minheap.empty() || num >= minheap.top()) {
            minheap.push(num);
        }
        else {
            maxheap.push(num);
        }
        if (maxheap.size() > minheap.size() + 1) {//����ʾ��������С�����������Ԫ��ʱ����һ��һ���ᴥ��������������µڶ�����ӵ�Ԫ�ر��������ӵ���С���У���û��ά������С��
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian() {
        if (minheap.size() > maxheap.size()) {
            return minheap.top();
        }
        else if (maxheap.size() > minheap.size()) {
            return maxheap.top();
        }
        else {
            return (double)(minheap.top() + maxheap.top()) / 2;
        }
    }
};
void test() {
    MedianFinder medianFinder = {};
    medianFinder.addNum(-1);
    medianFinder.addNum(-2);
    medianFinder.addNum(-3);
    cout << medianFinder.findMedian() << endl;
    while (!medianFinder.maxheap.empty()) {
        cout << medianFinder.maxheap.top() << ",";
        medianFinder.maxheap.pop();
    }
    cout << endl;
    while (!medianFinder.minheap.empty()) {
        cout << medianFinder.minheap.top() << ",";
        medianFinder.minheap.pop();
    }
    cout << endl;

}