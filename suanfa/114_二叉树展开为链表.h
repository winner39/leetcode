#pragma once
#include "dependencies.h"
struct TreeNode {//10:54-11:12
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> preorder;
        TreeNode* father = new TreeNode(-1);
        preorder.push(root);
        if (root) {
            while (!preorder.empty()) {
                TreeNode* node = preorder.top();
                preorder.pop();
                if (node->right) {
                    preorder.push(node->right);
                }
                if (node->left) {
                    preorder.push(node->left);
                }
                father->right = node;
                father = node;
                father->left = nullptr;
            }
        }
    }
};