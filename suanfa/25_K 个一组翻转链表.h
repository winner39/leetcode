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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 1;
        bool isinit = false;
        ListNode* result = head;
        ListNode* check = head;
        ListNode* node_1 = head, * node_2 = head,* pre_head = head;
        while (true) {
            while (check->next && count < k) {
                check = check->next;
                count++;
            }
            if (count == k) {
                count = 1;
                node_2 = check;
                pre_head->next = node_2;
                pre_head = node_1;
                check = check->next;
                while (node_1 != node_2) {
                    ListNode* temp = node_1->next;
                    node_1->next = node_2->next;
                    node_2->next = node_1;
                    node_1 = temp;
                }
                node_1 = check;
                if (!isinit) {
                    isinit = true;
                    result = node_2;
                }
            }
            else return result;
        }
    }
};