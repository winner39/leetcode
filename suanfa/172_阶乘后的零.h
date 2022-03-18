#pragma once
#include "dependencies.h"
class Solution {
public:
    int trailingZeroes(int n) {
        int zero = 0,index=5;
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
        cout << zero << endl;
        return zero;
    }
};
void test() {
    Solution solution = {};
    solution.trailingZeroes(30);
}