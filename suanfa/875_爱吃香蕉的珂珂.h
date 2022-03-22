#pragma once
#include "dependencies.h"
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long int min_speed = 1;
        while (cal_h(piles,min_speed) > h) {//找到一个供于二分搜索的上界，使得所需时间无法满足吃光香蕉
            min_speed *= 2;
        }
        min_speed = binary_search_smaller(piles, h, min_speed / 2 + 1, min_speed);
        return min_speed;
    }
    int binary_search_smaller(vector<int>& piles,int target, int left, int right) {//即便时间刚好满足，也尽量减少进食速度，因此当左右边界重合时，可能会出现无法吃光香蕉的情况
        int mid = left + (right - left) / 2;
        if (left == right) {
            if (cal_h(piles,left)>target) {
                return left - 1;
            }
            else return left;
        }
        else if (cal_h(piles,mid) > target) {
            return binary_search_smaller(piles, target, mid + 1,right);
        }
        else {
            return binary_search_smaller(piles, target, left, mid);
        }
    }
    long long int cal_h(vector<int>& piles,int speed) {//计算在speed速度下所需时间
        long long int total = 0;
        for (int i = 0; i < piles.size(); i++) {
            int extra = (piles[i] % speed) == 0 ? 0 : 1;
            total += piles[i] / speed + extra;
        }
        return total;
    }
};


void test() {
    Solution solution = {};
    vector<int> piles = { 312884470 };
    solution.minEatingSpeed(piles, 968709470);

}