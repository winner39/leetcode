#pragma once
#include "dependencies.h"
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> count(26);
        for (int i = 0; i < t.size(); i++) {
            count[t[i] - 'a'].push_back(i);
        }
        int temp = -1;
        for (int i = 0; i < s.size(); i++) {
            cout << s[i] <<","<<temp << endl;
            if (count[s[i] - 'a'].size()==0||(temp = binary_search(count[s[i] - 'a'], temp, 0, count[s[i] - 'a'].size()-1)) == -1) {
                return false;
            }
        }
        return true;
    }
    int binary_search(vector<int>& char_index, int target, int left, int right) {//寻找比target大的对应下标
        int mid = left + (right - left) / 2;
        if (char_index[mid] == target) {
            if (mid + 1 < char_index.size()) return char_index[mid + 1];
            else return -1;
        }
        else if (left == right) {
            if (char_index[left] > target) { 
                return char_index[left]; 
            }
            else if (left + 1 < char_index.size()){
                return char_index[left + 1];
            }
            else {
                return -1;
            }
        }
        else if (char_index[mid] > target) {
            return binary_search(char_index, target, left, mid);
        }
        else {
            return binary_search(char_index, target, mid + 1, right);
        }
    }
};
void test() {
    Solution solution = {};
    solution.isSubsequence("aaaaaa"
        ,"bbaaaa");
}