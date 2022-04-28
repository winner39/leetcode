#pragma once
#include "dependencies.h"
struct TreeNode {//11:21
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    struct Node {
        int signal;
        TreeNode* node;
        Node(TreeNode *a,int signal = 1):node(a),signal(signal){}
    };
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<Node> path;
        int temp = 0;
        if (!root) return result;
        path.emplace_back(root,2);
        temp += path.back().node->val;
        while (!path.empty()) {
            if (path.back().signal == 2) {
                path.back().signal = 1;
                while (path.back().node->left) {
                    path.emplace_back(path.back().node->left);
                    temp += path.back().node->val;
                }
            }
            else if (path.back().signal == 1) {
                path.back().signal = 0;
                if (path.back().node->right) {
                    path.emplace_back(path.back().node->right,2);
                    temp += path.back().node->val;
                }
            }
            else {
                if (!path.back().node->left && !path.back().node->right && targetSum == temp) {
                    result.push_back(vector<int>());
                    for (auto i : path) {
                        result.back().push_back(i.node->val);
                    }
                }
                temp -= path.back().node->val;
                path.pop_back();
            }
        }
        return result;
    }
};