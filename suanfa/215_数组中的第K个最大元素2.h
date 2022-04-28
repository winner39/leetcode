#pragma once
#include "dependencies.h"
class Solution {//20:30
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> maxheap;
        int index = 0, swap_index = 0;
        for (auto i : nums) {
            maxheap.push_back(i);
            index = maxheap.size() - 1;
            while (index != 0 && maxheap[(index - 1) / 2] < maxheap[index]) {
                swap(maxheap[(index - 1) / 2], maxheap[index]);
                index = (index - 1) / 2;
            }
        }
        int result = 0;
        for (int i = 0; i < k; i++) {
            result = maxheap[0];
            swap(maxheap[0], maxheap.back());
            maxheap.pop_back();
            index = 0;
            while (index * 2 + 2 < maxheap.size()) {
                if (maxheap[index * 2 + 1] > maxheap[index] || maxheap[index * 2 + 2] > maxheap[index]) {
                    swap_index = maxheap[index * 2 + 1] > maxheap[index * 2 + 2] ? index * 2 + 1 : index * 2 + 2;
                    swap(maxheap[index], maxheap[swap_index]);
                    index = swap_index;
                }
                else {
                    break;
                }
            }
            if (index * 2 + 1 < maxheap.size()) {
                if (maxheap[index * 2 + 1] > maxheap[index]) {
                    swap(maxheap[index], maxheap[index * 2 + 1]);
                }
            }
        }
        return result;
    }
};
void test() {
    Solution solution = {};
    vector<int> ask = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    cout << solution.findKthLargest(ask, 4) << endl;
}