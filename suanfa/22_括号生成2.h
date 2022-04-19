#pragma once
#include "dependencies.h"
class Solution { //16:41
public:
    vector<string> generateParenthesis(int n) {//n+1������ǳ����¼ӵ������⣬ʣ���n��������i�����¼ӵ��������棬��n-i�����¼ӵ���������
        if (n == 0) {
            return vector<string>();
        }
        if (n == 1) {
            return vector<string>(1, "()");
        }
        vector<vector<string>> memory(n + 1);
        memory[0].push_back("");
        memory[1].push_back("()");
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (string p1 : memory[j]) {
                    for (string p2 : memory[i - j - 1]) {
                        memory[i].push_back("(" + p1 + ")" + p2);
                    }
                }
            }
        }
        return memory.back();
    }
};
void test() {
    Solution solution = {};
    vector<string> result = solution.generateParenthesis(3);
}