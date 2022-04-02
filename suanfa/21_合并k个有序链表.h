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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
        ListNode* base = list1, * compare = list2, * result = list1;
        if (list2->val <= list1->val) {
            base = list2;
            compare = list1;
            result = base;
        }
        while (compare!=nullptr) {
            if (base->next == nullptr) {
                base->next = compare;
                break;
            }
            if (base->val <= compare->val && base->next->val > compare->val) {
                cout << base->val << "," << compare->val << endl;
                ListNode* temp = compare->next;
                compare->next = base->next;
                base->next = compare;
                compare = temp;
            }
            base = base->next;
        }
        return result;
    }
};