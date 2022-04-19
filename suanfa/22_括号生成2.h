#pragma once
#include "dependencies.h"
class Solution { //16:41
public:
    vector<string> generateParenthesis(int n) {//n+1层仅考虑除了新加的括号外，剩余的n个括号有i个在新加的括号里面，有n-i个在新加的括号外面
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