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
    bool isPalindrome(ListNode* head) {
        ListNode* left = head, * right = head;
        if (!head->next) return true;
        while (right->next&&right->next->next) {
            left = left->next;
            right = right->next->next;
        }
        if (right->next) right = right->next;
        left = left->next;
        reverselist(left);
        left = head;
        ListNode* temp = right;
        while (left&&right&&left->val == right->val) {
            left = left->next;
            right = right->next;
        }
        reverselist(temp);//链表结构还原
        if (!left || !right) {
            return true;
        }
        else return false;
    }
    void reverselist(ListNode* head) {
        ListNode* left = head, * right = head;
        while (right->next) {
            right = right->next;
        }
        while (left != right) {
            ListNode* backup = left->next;
            left->next = right->next;
            right->next = left;
            left = backup;
        }
    }
};