#pragma once
#include "dependencies.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front = head, *back = head;
        int i;
        for (i = 0; i < n; i++) {
            if (back->next != nullptr)
                back = back->next;
            else break;
        }
        if (i != n) return head->next;
        while (back->next != nullptr) {
            front = front->next;
            back = back->next;
        }
        front->next = front->next->next;
        return head;
    }
};