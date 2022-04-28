#pragma once
#include "dependencies.h"
class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int, vector<int>, less<int>> maxheap;
    unordered_map<int, pair<int, int>> loginfo;
    int garbage_left = 0, garbage_right = 0;

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {//核心思想：因为堆无法删除非堆顶元素，所以只要当删除的元素不影响判断中位数时，记住他占的坑，在这个基础上维持最大最小堆平衡
        vector<double> result;
        for (int i = 0; i < k; i++) {
            push_queue(nums[i]);
        }
        result.push_back(get_middle(k));
        for (int i = k; i < nums.size(); i++) {
            if (nums[i - k] >= minheap.top()) {//可能会出现重复数，导致要删除的数其实位于另一侧的情况，但不管你删的是最大还是最小堆的堆顶，其实经过平衡后都会得到同一组堆
                loginfo[nums[i - k]].second++;
                garbage_right++;
            }
            else {
                loginfo[nums[i - k]].first++;
                garbage_left++;
            }
            //while (delete_queue()) {//可有可无，因为在进入下一次循环前最大最小堆已经是平衡状态，考虑进1个garbage的情况下，他们之间的size最多差2，push后size最大差3，经过一次balance可以平衡到差1
            //    balance_queue();
            //}
            push_queue(nums[i]);//因此根据上面的注释，此时push后两个堆必平衡
            while (delete_queue()) {
                //balance_queue();//当传球传的是垃圾时，需要及时调整,但其实不需要，因为删的都是垃圾，不可能影响两个堆的平衡
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
    void balance_queue() {//当垃圾不在堆顶不会影响到判断中位数时，只要记住最大最小堆的垃圾数量，可以在这个基础上维持平衡且不影响中位数平衡
        if (minheap.size() - garbage_right > maxheap.size() - garbage_left + 1) {
            if (loginfo[minheap.top()].second > 0) {//当传球传的是垃圾时，需要及时调整,但其实不需要，因为删的都是垃圾，不可能影响两个堆的平衡
                //而且正常push后也不会使在堆顶的垃圾需要转移，自己分情况讨论，垃圾在堆顶的4种情况：垃圾如果是最大最小堆的堆顶（2种）*下一次push的元素出现在最大堆还是最小堆（2种）
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
    bool delete_queue() {//不停地删除位于栈顶的垃圾
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