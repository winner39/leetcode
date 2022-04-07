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
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) return nullptr;
        int cycle_Length = 1;
        ListNode* slow = head, * fast = head->next;
        while (slow != fast) {
            if (!fast || !fast->next) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            cycle_Length++;
        }
        fast = head;
        while (slow->next != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};