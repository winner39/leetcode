#pragma once
#include "dependencies.h"
class Solution {
public:
    string convertToBase7(int num) {
        bool vice = false;
        if (num < 0) {
            vice = true;
            num = -num;
        }
        string result;
        int a = 0;
        int index = 0,former_index = 0;
        int temp = 0;
        while (true) {
            index = 0;
            temp = num;
            a = temp;
            while ((temp /= 7) != 0) {
                index++;
                a = temp;
            }
            num -= pow(7, index) * a;
            for (int i = index; i < former_index - 1; i++) {
                result += '0';
            }
            result += '0' + a;
            former_index = index;
            if(index == 0){
                if (vice) result.insert(0, "-");
                return result;
            }
        }
    }
};
void test() {
    Solution solution = {};
    solution.convertToBase7(-7);
}
// 一个更棒的方法
//class Solution {
//    public String convertToBase7(int num) {
//        StringBuilder sb = new StringBuilder();
//        if (num == 0) return "0";
//        boolean flag = num < 0;
//        num = Math.abs(num);
//        while (num != 0) {
//            sb.append(num % 7);
//            num /= 7;
//        }
//        if (flag)
//            sb.append("-");
//        return sb.reverse().toString();
//    }
//}