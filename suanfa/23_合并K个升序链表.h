#pragma once
#include "dependencies.h"
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *result = new ListNode(-1);
        ListNode* pre_Node = result;
        deque<ListNode*> ptr;
        for (auto i : lists) {
            if(i != nullptr)
                ptr.push_back(i);
        }
        if (ptr.empty()) return nullptr;
        while (ptr.size()>1) {
            while (ptr[0] && ptr[1]) {
                if (ptr[0]->val < ptr[1]->val) {
                    pre_Node->next = ptr[0];
                    pre_Node = pre_Node->next;
                    ptr[0] = ptr[0]->next;
                }
                else {
                    pre_Node->next = ptr[1];
                    pre_Node = pre_Node->next;
                    ptr[1] = ptr[1]->next;
                }
            }
            pre_Node->next = ptr[0] ? ptr[0] : ptr[1];
            ptr.push_back(result->next);
            ptr.pop_front();
            ptr.pop_front();
            result = new ListNode(-1);
            pre_Node = result;
        }
        return ptr.front();
    }
};