#pragma once
#include "dependencies.h"
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const;
};


class NestedIterator {
public:
    struct ListLog {
        int size;
        int cur_index = 0;
        vector<NestedInteger>::iterator i;
        ListLog(vector<NestedInteger>& v_n) {
            i = v_n.begin();
            size = v_n.size();
        }
    };
    vector<NestedInteger> nestedList;
    vector<ListLog> vec_it;
    NestedIterator(vector<NestedInteger>& nestedList) {
        this->nestedList = nestedList;
        vec_it.emplace_back(nestedList);
    }

    int next() {
        int result;
        if (vec_it.back().i->isInteger()) {
            result = vec_it.back().i->getInteger();
            vec_it.back().i++;
            vec_it.back().cur_index++;
            return result;
        }
        while (!vec_it.back().i->isInteger()) {
            vector<NestedInteger>::iterator temp = vec_it.back().i;
            vec_it.back().i++;
            vec_it.back().cur_index++;
            vec_it.emplace_back(temp->getList());
        }
        result = vec_it.back().i->getInteger();
        vec_it.back().i++;
        vec_it.back().cur_index++;
        return result;
    }

    bool hasNext() {
        vector<NestedInteger>::const_iterator temp;
        while (!vec_it.empty()) {
            temp = vec_it.back().i;
            while (!temp->isInteger()) {
                temp = temp->getList().begin();
            }
            if()
            if (vec_it.back().cur_index == vec_it.back().size) {
                vec_it.pop_back();
            }
        }
        return !vec_it.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */