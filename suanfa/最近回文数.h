#pragma once
#include "dependencies.h"
class Solution {
public:
    string nearestPalindromic(string n) {
        int length = n.size();
        bool jishu = false;
        string result, result2;
        long int num = stringtolong(n);
        if ((result2 = special(n, length)) != "null") {
            return result2;
        }
        if (n.size() == 1) {
            result = n;
            jishu = true;
        }
        else {
            for (int i = 0; i < length / 2; i++) {
                result.insert(i, 2, n[i]);
            }
            if ((length & 1) != 0) {
                result.insert(length / 2, 1, n[length / 2]);
                jishu = true;
            }
        }
        if (result > n) {
            result2 = result;
            result = decrease(result, jishu, length);
        }
        else if (result == n) {
            result2 = increase(result, jishu, length);
            result = decrease(result, jishu, length);
        }
        else {
            result2 = increase(result, jishu, length);
        }
        long int num1 = stringtolong(result), num2 = stringtolong(result2);
        return (num - num1) <= (num2 - num) ? result : result2;
    }
    long int stringtolong(std::string str)
    {
        long int result;
        stringstream ss;
        ss << str;
        ss >> result;
        return result;
    }
    string decrease(string result, bool jishu, int length) {
        int pos = 0;
        if (jishu) {
            pos = length / 2;
        }
        else {
            pos = length / 2 - 1;
        }
        if (result[pos] == '0') {
            result[pos] = '9';
            while (--pos >= 0 && result[pos] == '0') {
                result[pos] = '9';
            }
            if (pos == 0) {
                if (result[pos] == '1') {
                    result.erase(0, 1);
                    length--;
                    result.assign(length, '9');
                    return result;
                }
                else {
                    result[pos]--;
                }
            }
            else {
                result[pos]--;
            }
        }
        else {
            result[pos]--;
        }
        for (int i = 0; i < length / 2; i++) {
            result[length - i - 1] = result[i];
        }
        return result;
    }
    string increase(string result, bool jishu, int length) {
        int pos = 0;
        if (jishu) {
            pos = length / 2;
        }
        else {
            pos = length / 2 - 1;
        }
        if (result[pos] == '9') {
            result[pos] = '0';
            while (--pos >= 0 && result[pos] == '9') {
                result[pos] = '0';
            }
            if (pos == -1) {
                if (result[0] == '0') {
                    result.insert(0, 1, '1');
                    length++;
                }
                else {
                    result[0]++;
                }
            }
            else {
                result[pos]++;
            }
        }
        else {
            result[pos]++;
        }
        for (int i = 0; i < length / 2; i++) {
            result[length - i - 1] = result[i];
        }
        return result;
    }
    string special(string& result, int length) {
        string temp;
        if (result == "0") {
            return "1";
        }
        else if (result == "11") {
            return "9";
        }
        else if (result == "10") {
            return "9";
        }
        else {
            return "null";
        }
    }
};
void test() {
    string n = "10001";
    Solution solution = {};
    cout << solution.nearestPalindromic(n);
}