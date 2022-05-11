#pragma once
#include "dependencies.h"
struct TreeNode {//18:43-19:40
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        vector<TreeNode*> q;
        TreeNode* signal = new TreeNode(0);
        int indexoflast,i;
        if (root) {
            TreeNode* node;
            q.push_back(root);
            while (!q.empty()) {
                indexoflast = q.size();
                for (i = 0; i < indexoflast; i++) {
                    node = q[i];
                    swap(node->left, node->right);
                    if (node->left) {
                        q.push_back(node->left);
                    }
                    if (node->right) {
                        q.push_back(node->right);
                    }
                }
                q.erase(q.begin(), q.begin() + indexoflast);
            }
        }
        return root;
    }
};