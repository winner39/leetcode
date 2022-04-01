#pragma once
#include "dependencies.h"
class Solution {
public:
    int trap(vector<int>& height) {//单调栈，当出现山峰高度大于栈顶元素时，进行出栈操作进行统合，保证计算积水量时用最少的次数
        int result = 0;
        int left;
        stack<int> peak;
        if (height.size() <= 2) {
            return 0;
        }
        else {
            peak.push(0);
            left = 0;
            for (int i = 1; i < height.size(); i++) {
                if (i==height.size()-1||height[i - 1] < height[i] && height[i + 1] <= height[i]) {
                    while (!peak.empty() && height[peak.top()] <= height[i]) {
                        peak.pop();
                    }
                    peak.push(i);
                    if (peak.size() == 1) {
                        result += cal_height_bwt_peak(left, i, height);
                        left = i;
                    }
                }
            }
            while (peak.size()>1) {
                int right = peak.top();
                peak.pop();
                result += cal_height_bwt_peak(peak.top(), right, height);
            }
            return result;
        }
    }
    int cal_height_bwt_peak(int i, int j,vector<int>&height) {
        int baseline = height[i] <= height[j] ? height[i] : height[j];
        int result = 0;
        for (int temp = i + 1; temp < j; temp++) {
            if (baseline > height[temp]) {
                result += (baseline - height[temp]);
            }
        }
        return result;
    }
    static void printint(int temp) {
        cout << temp << ",";
    }
};
void test() {
    Solution solution = {};
    vector<int> input = { 4,2,0,3,5,1 };
    cout << solution.trap(input);
}