#pragma once
#include "dependencies.h"
struct TreeNode {//17:09
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int left = 1e6, right = 1e6;
        if (!root->left && !root->right) {
            return 1;
        }
        if (root->left) {
            left = 1 + minDepth(root->left);
        }
        if (root->right) {
            right = 1 + minDepth(root->right);
        }
        return left < right ? left : right;
    }
};