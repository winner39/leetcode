#pragma once
#include "dependencies.h"
class Solution {
public:
    vector<int> boolean_count;
    int numberOfGoodSubsets(vector<int>& nums) {
        long int total = 0;
        vector<int> count(31, 0);
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        for (int i = 1; i < 31; i++) {
            if (count[i] > 0) max = i;
        }
        boolean_count = vector<int>();
        boolean_count.push_back(2);
        boolean_count.push_back(3);
        boolean_count.push_back(5);
        boolean_count.push_back(7);
        boolean_count.push_back(11);
        boolean_count.push_back(13);
        boolean_count.push_back(17);
        boolean_count.push_back(19);
        boolean_count.push_back(23);
        boolean_count.push_back(29);
        for (int i = 0; i < boolean_count.size(); i++) {
            if (boolean_count[i] > max) {
                boolean_count.erase(boolean_count.begin() + i, boolean_count.end());
                break;
            }
        }
        deque<int> used = deque<int>();
        total = add_total(count, used, boolean_count.size(),0);
        long int index = 1;
        for (int i = 0; i < count[1]; i++) {
            index *= 2;
            index %= (long int)(1e9 + 7);
        }
        int result = (total * index) % (long int)(1e9 + 7);
        return result;
    }
    long int add_total(vector<int>& count, deque<int>& used, int min,long int numberofgoodsets) {
        long int temp = 0;
        //long int result = numberofgoodsets;
        long int result = 0;
        if (min >= 1) {
            for (int i = min - 1; i >= 0; i--) {
                used.push_front(boolean_count[i]);
                if (count[boolean_count[i]] > 0) {
                    if (numberofgoodsets == 0) {
                        numberofgoodsets = count[boolean_count[i]];
                    }
                    else {
                        numberofgoodsets *= count[boolean_count[i]] % (long int)(1e9 + 7);
                    }
                    result += numberofgoodsets % (long int)(1e9 + 7);
                    /*if (i == 0 && count[boolean_count[0]] == 0) {
                        result = 0;
                    }*/
                }
                result += hebing(count, used, i + 1) % (long int)(1e9 + 7);
                result += add_total(count, used, i, numberofgoodsets) % (long int)(1e9 + 7);
                used.pop_front();
            }
        }
        return result;
    }
    long int cal(vector<int>& count, deque<int>& used) {
        long int result = 1;
        for (int i = 0; i < used.size(); i++) {
            result *= count[used[i]];
            if (result == 0) {
                break;
            }
            result %= (long int)(1e9 + 7);
        }
        return result;
    }
    long int hebing(vector<int>& count, deque<int>& used, int min) {
        long int temp = 0;
        long int result = 0;
        long int index_ = 0;
        //cout << "used[0]:" << used[0] << " boolean_count:" << boolean_count[min - 1] << endl;
        if (used.size() > 1 && used[0] == boolean_count[min - 1]) {
            for (int n = 1; n < used.size(); n++) {
                index_ = used[0] * used[n];
                //cout << "index_:"<<index_ << endl;
                if (index_ <= 30) {
                    deque<int> temp_used = used;
                    temp_used.erase(temp_used.begin() + n);
                    temp_used.pop_front();
                    if (temp_used.size() > 0) {
                        int k = 0;
                        for (k = 0; k < temp_used.size(); k++) {
                            if (temp_used[k] > index_) {
                                temp_used.insert(temp_used.begin() + k, index_);
                                break;
                            }
                        }
                        if (k == temp_used.size()) {
                            temp_used.insert(temp_used.end(), index_);
                        }
                    }
                    else {
                        temp_used.push_front(index_);
                    }
                    result += cal(count, temp_used) % (long int)(1e9 + 7);
                    result += add_total(count, temp_used, min - 1, result) % (long int)(1e9 + 7);
                }
                else {
                    break;
                }
            }
        }
        return result;
    }
    void output(deque<int>& used) {
        if (used.size() == 0) {
            cout << "null" << endl;
            return;
        }
        for (int i = 0; i < used.size(); i++) {
            cout << used[i] << ",";
        }
        cout << endl;
    }
};

void test() {
    Solution solution;
    vector<int> nums = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
    /*for (int i = 1; i < 21; i++) {
        nums.push_back(i);
    }*/
    cout << solution.numberOfGoodSubsets(nums) << endl;
}