#pragma once
#include "dependencies.h"
struct TreeNode {//15:30
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    unordered_map<int, int> inMap;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return build(0, inorder.size() - 1, inorder.size() - 1, inorder, postorder);
    }
    TreeNode* build(int left, int right, int target, vector<int>& inorder, vector<int>& postorder) {
        int in_index = inMap[postorder[target]];
        TreeNode* leftNode = nullptr, * rightNode = nullptr;
        if (in_index - 1 == left) {
            leftNode = new TreeNode(inorder[in_index - 1]);
        }
        else if (left < in_index - 1) {
            leftNode = build(left, in_index - 1, target - (right - in_index) - 1, inorder, postorder);
        }
        if (in_index + 1 == right) {
            rightNode = new TreeNode(inorder[in_index + 1]);
        }
        else if (right > in_index + 1) {
            rightNode = build(in_index + 1, right, target - 1, inorder, postorder); 
        }
        TreeNode* root = new TreeNode(postorder[target]);
        root->left = leftNode;
        root->right = rightNode;
        return root;
    }
};