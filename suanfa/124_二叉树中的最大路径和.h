#pragma once
#include "dependencies.h"
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define MIN_INT -2147483648
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int result = MIN_INT;
        get_max(root, result);
        return result;
    }

    int get_max(TreeNode* t,int &result) {
        if (!t->left && !t->right) {
            if (t->val > result) result = t->val;
            return t->val;
        }
        else {
            int bias = 0;
            int left_sum = 0, right_sum = 0;
            if (t->left) left_sum = get_max(t->left, result);
            if (t->right) right_sum = get_max(t->right, result);
            bias = left_sum > right_sum ? left_sum : right_sum;
            int temp = t->val + (left_sum > 0 ? left_sum : 0) + (right_sum > 0 ? right_sum : 0);
			if (temp > result) {
                result = temp;
            }
            if (bias > 0) {
                return bias + t->val;
            }
            else return t->val;
        }
    }
};