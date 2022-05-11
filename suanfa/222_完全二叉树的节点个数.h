#pragma once
#include "dependencies.h"
struct TreeNode {//19:41-21:12
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root) {
            TreeNode* node = root;
            int right = 0, base_right = 1, result = 2;
            while (node->right) {
                node = node->right;
                base_right++;
                result = result << 1;
            }
            result--;
            TreeNode* r = root;
            int base = 2;
            int extra = result + 1;
            while (true) {
                int i = base;
                if (r->left && !r->right) {
                    result += 1;
                    return result;
                }
                else if(r->left) {
                    node = r->left;
                }
                else return result;
                while (node->right) {
                    node = node->right;
                    i++;
                }
                if (i > base_right) {
                    r = r->right;
                    extra = extra >> 1;
                    result += extra;
                }
                else {
                    r = r->left;
                    extra = extra >> 1;
                }
                base++;
            }
        }
        return 0;
    }
};