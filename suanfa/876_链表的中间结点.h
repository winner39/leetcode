#pragma once
#include"dependencies.h"
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, * fast = head;
        if (!head) return nullptr;
        while (fast->next&&fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next) return slow->next;
        else return slow;
    }
};