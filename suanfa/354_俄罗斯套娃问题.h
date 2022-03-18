#pragma once
#include "dependencies.h"
class Solution {
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        if (v1[0] < v2[0] && v1[1] < v2[1]) return true;
        return false;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<vector<int>> memory(envelopes.size());
        for (auto iter = memory.begin(); iter < memory.end(); iter++) {
            (*iter).resize(envelopes.size(),0);
        }
        for (int i = 0; i < envelopes.size(); i++) {
            for (int j = 0; j < envelopes.size(); j++) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) memory[i][j] = 1;
                else { memory[i][j] = 0; }
                cout << memory[i][j] << ",";
            }
            cout << endl;
        }
        return max(memory[envelopes.size() - 1]) + 1;
    }
    
    int max(vector<int> &memory) {
        int result = -1;
        for(auto iter = memory.begin();iter<memory.end();iter++){
            if (*iter > result) result = *iter;
        }
        return result;
    }
    static void printa(vector<int>& temp) {
        cout << "{" << temp[0] << "," << temp[1] << "}";
        cout << ",";
    }
};
void test() {
    Solution solution = {};
    vector<vector<int>> temp= { {1,3},{3,5},{6,7},{6,8},{8,4},{9,5}};

    cout << solution.maxEnvelopes(temp);
    
}