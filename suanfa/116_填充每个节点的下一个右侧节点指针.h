#pragma once
#include "dependencies.h"
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> levelorder;
        Node* signal = new Node();
        if (root) {
            levelorder.push(root);
            levelorder.push(signal);
            while (!levelorder.empty()) {
                while (true) {
                    Node* node = levelorder.front();
                    if (node->left) {
                        levelorder.push(node->left);
                        levelorder.push(node->right);
                    }
                    levelorder.pop();
                    if (!levelorder.empty() && levelorder.front() != signal) {
                        node->next = levelorder.front();
                    }
                    else break;
                }
                levelorder.pop();
                levelorder.push(signal);
            }
        }
        return root;
    }
};