#pragma once
#include "dependencies.h"
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        num1.erase(num1.end() - 1);
        num2.erase(num2.end() - 1);
        string num[2] = { num1,num2 };
        int a[2], b[2];
        int j = 0;
        for (int i = 0; i < 2; i++) {
            j = num[i].find('+');
            a[i] = atoi(num[i].substr(0, j).c_str());
            b[i] = atoi(num[i].substr(j + 1).c_str());
        }
        int shi, xu;
        cout << a[0] << "," << b[0] << "," << a[1] << "," << b[1] << endl;
        shi = a[0] * a[1] - (b[0] * b[1]); 
        xu = a[0] * b[1] + a[1] * b[0];
        string result;
        result += to_string(shi);
        result += '+';
        result += to_string(xu) + 'i';
        cout << result << endl;
        return result;
    }
};
void test() {
    string test = "-2+-1i";
    string test2 = "5+1i";
    Solution solution = Solution();
    solution.complexNumberMultiply(test, test2);
}