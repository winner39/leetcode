#pragma once
#include "dependencies.h"
class Solution {
public:
    int preimageSizeFZF(int k) {
        long int zero = 0, i = 1;
        while (zero < k) {
            zero = cal_zero(i*=2);
        }
        if (zero == k) return 5;
        else {
            if (binary_search(k, i / 2, i)) return 5;
        }
        return 0;
    }
    int cal_zero(long int n) {
        long int zero = 0, index = 5;
        while (1) {
            int extra_zero = n / index;
            if (extra_zero != 0) {
                zero += extra_zero;
            }
            else {
                break;
            }
            index *= 5;
        }
        return zero;
    }
    bool binary_search(long int target,long int left,long int right) {
        long int mid = left + (right - left) / 2;
        long int temp = cal_zero(mid);
        if (temp == target) {
            return true;
        }
        else if (left == right) {
            return false;
        }
        else if (temp > target) {
            return binary_search(target, left, mid);
        }
        else {
            return binary_search(target, mid + 1, right);
        }
    }
};  

void test() {
    Solution solution = {};
    solution.preimageSizeFZF(1);
}                                                                                                                                                                                                                                                                                                                                        