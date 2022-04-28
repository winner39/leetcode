#pragma once
#include"dependencies.h"
class MedianFinder {//10:31-16:47
public:
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {

    }

    void addNum(int num) {//同时用最大堆与最小堆维护，当两者size趋近或相等时，说明堆顶元素确实比一半的元素 大/小              
        if (minheap.empty() || num >= minheap.top()) {
            minheap.push(num);
        }
        else{
            maxheap.push(num);
        }
        if (minheap.size() > maxheap.size() + 1) {//比堆顶元素小的元素超过一半，说明该堆顶元素不是中位数，将该元素传球到另一侧堆，维持size平衡，而该最小堆的下一位继任者必然比一半的元素小
            maxheap.push(minheap.top());//实际有点施舍的意思，这样会导致最大堆的最大值比最小堆的最小值小
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