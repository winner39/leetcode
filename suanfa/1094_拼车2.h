#pragma once
#include "dependencies.h"
class Solution {
public:
    class flow{
    public:
        int passenger;
        int date;
        flow(int a,int b):passenger(a),date(b){}
        friend bool operator< (const flow& a,const flow& b) {
            return a.date > b.date;
        }
    };
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<flow> temp;
        for (auto i : trips) {
            temp.push(flow(i[0], i[1]));
            temp.push(flow(-i[0], i[2]));
        }
        int count = 0, pre_date = temp.top().date;
        while (!temp.empty()) {
            if (temp.top().date != pre_date) {
                if (count > capacity) return false;
                pre_date = temp.top().date;
            }
            count += temp.top().passenger;
            temp.pop();
        }
        if (count > capacity) return false;
        return true;
    }
};