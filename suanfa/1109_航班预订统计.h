#pragma once
#include "dependencies.h"
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> result(n + 1,0);
        for (auto i : bookings) {
            result[i[0] - 1] += i[2];
            result[i[1]] -= i[2];
        }
        result.pop_back();
        for (int i = 1; i < result.size(); i++) {
            result[i] += result[i - 1];
        }
        return result;
    }
};