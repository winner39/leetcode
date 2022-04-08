#pragma once
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* left = head,* right = head->next;
        while (left) {
            if (right&&right->val == left->val) {
                right = right->next;
            }
            else {
                left->next = right;
                left = right;
            }
        }
        return head;
    }
};