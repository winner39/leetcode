#pragma once
#include "dependencies.h"
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        vector<vector<int>> union_;
        while (i != firstList.size() && j!= secondList.size()) {
            if (firstList[i][0] > secondList[j][1]) {
                j++;
            }
            else if (firstList[i][1] < secondList[j][0]) {
                i++;
            }
            else {
                union_.emplace_back(2,0);
                union_.back()[0] = firstList[i][0] >= secondList[j][0] ? firstList[i][0] : secondList[j][0];
                union_.back()[1] = firstList[i][1] <= secondList[j][1] ? firstList[i][1] : secondList[j][1];
                firstList[i][1] >= secondList[j][1] ? j++ : i++;//相等时其实i和j可以一起++，但依赖下次循环调整也可以
            }
        }
        return union_;
    }
};