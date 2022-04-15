#pragma once
#include "dependencies.h"
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int> a, vector<int> b)->bool {return a[1] < b[1]; });
        vector<vector<int>> temp = trips;
        sort(temp.begin(), temp.end(), [](vector<int> a, vector<int> b)->bool {return a[2] < b[2]; });
        int count = 0, enter = 0, leave = 0;
        while (enter < trips.size()) {
            if (trips[enter][1] < temp[leave][2]) {
                count += trips[enter++][0];
                if (count > capacity) return false;
            }
            else if (trips[enter][1] == temp[leave][2]) {
                count += trips[enter++][0] - temp[leave++][0];
            }
            else {
                count -= temp[leave++][0];
            }
        }
        return true;
    }
};