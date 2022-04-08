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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* node_Left = head, * node_Right = head, *pre_Node = head;
        if (!head) return nullptr;
        for (int i = 1; i < left - 1; i++) {
            node_Left = node_Left->next;
        }
        if (left > 1) {
            pre_Node = node_Left;
            node_Left = node_Left->next;
        }
        node_Right = node_Left;
        int temp = right - left;
        for (int i = 0; i < temp; i++) {
            node_Right = node_Right->next;
        }
        while (node_Left != node_Right) {
            ListNode* temp_node = node_Left->next;
            node_Left->next = node_Right->next;
            node_Right->next = node_Left;
            node_Left = temp_node;
        }
        if (left == 1) {
            return node_Right;
        }
        else{
            pre_Node->next = node_Right;
            return head;
        }
    }
};