#pragma once
#include "dependencies.h"
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        list<Node*> node_list;
        if (root != nullptr) {
            node_list.push_front(root);
            while (!node_list.empty()) {
                Node* temp = node_list.front();
                result.push_back(temp->val);
                node_list.pop_front();
                for (int i = temp->children.size() - 1; i >= 0; i--) {
                    node_list.push_front(temp->children[i]);
                }
            }
        }
        return result;
    }
};
void test() {
    Node* root = new Node(5);
    Node* root1 = new Node(2);
    Node* root2 = new Node(3);
    Node* root3 = new Node(4);
    root->children = { root1 ,root2 ,root3 };
    Solution solution = {};
    solution.preorder(root);
    
}