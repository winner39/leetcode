#pragma once
#include "dependencies.h"
struct TreeNode {//
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int max = -1,max_index;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) max = nums[i],max_index = i;
        }
        TreeNode* root = build(0, nums.size(), nums);
        return root;
    }
    TreeNode* build(int left, int right, vector<int>& nums) {
        int max = -1, max_index;
        for (int i = left; i < right; i++) {
            if (nums[i] > max) max = nums[i], max_index = i;
        }
        TreeNode* node = new TreeNode(max);
        if (max_index > left) {
            node->left = build(left, max_index, nums);
        }
        if (max_index < right - 1) {
            node->right = build(max_index + 1, right, nums);
        }
        return node;
    }
};