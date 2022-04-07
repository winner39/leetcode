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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* a = headA, * b = headB;
        int lengthA = 0, lengthB = 0;
        while (a->next != nullptr) {
            a = a->next;
            lengthA++;
        }while (b->next != nullptr) {
            b = b->next;
            lengthB++;
        }
        int distance = 0, signal = 0;
        ListNode* temp = nullptr;
        if (lengthA > lengthB) {
            distance = lengthA - lengthB;
            signal = 0;
            temp = headA;
        }
        else {
            distance = lengthB - lengthA;
            signal = 1;
            temp = headB;
        }
        while (distance-- > 0) {
            temp = temp->next;
        }
        if (signal) {
            a = headA; b = temp;
        }
        else {
            a = temp; b = headB;
        }
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};