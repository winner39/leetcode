#pragma once
#include "dependencies.h"
class RandomizedSet {
public:
    unordered_map<long int, int> map;
    vector<long int> vec;
    RandomizedSet() {
        srand(time(0));
    }
    bool insert(int val) {
        if (map.find(val) == map.end()) {
            vec.push_back(val);
            map[val] = vec.size() - 1;
            return true;
        }
        return false;
    }
    bool remove(int val) {
        if (map.find(val) != map.end()) {
            int index = map[val];
            if (index != vec.size() - 1) {
                swap(vec[index], vec.back());
                vec.pop_back();
                map[vec[index]] = index;
                map.erase(val);
            }
            else {
                vec.pop_back();
                map.erase(val);
            }
            return true;
        }
        return false;
    }
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

void test() {
    RandomizedSet randomizedSet = {};
    randomizedSet.remove(0);
    randomizedSet.remove(0);
    randomizedSet.insert(0);
    randomizedSet.getRandom();
    randomizedSet.remove(0);
    randomizedSet.insert(0);
}
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */