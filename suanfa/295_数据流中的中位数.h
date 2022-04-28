#pragma once
#include"dependencies.h"
class MedianFinder {//10:31-16:47
public:
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {

    }

    void addNum(int num) {//ͬʱ����������С��ά����������size���������ʱ��˵���Ѷ�Ԫ��ȷʵ��һ���Ԫ�� ��/С              
        if (minheap.empty() || num >= minheap.top()) {
            minheap.push(num);
        }
        else{
            maxheap.push(num);
        }
        if (minheap.size() > maxheap.size() + 1) {//�ȶѶ�Ԫ��С��Ԫ�س���һ�룬˵���öѶ�Ԫ�ز�����λ��������Ԫ�ش�����һ��ѣ�ά��sizeƽ�⣬������С�ѵ���һλ�����߱�Ȼ��һ���Ԫ��С
            maxheap.push(minheap.top());//ʵ���е�ʩ�����˼�������ᵼ�����ѵ����ֵ����С�ѵ���СֵС
            minheap.pop();
        }
        else if (maxheap.size() > minheap.size()) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }

    double findMedian() {
        if (minheap.size() > maxheap.size()) {
            return minheap.top();
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