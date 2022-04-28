#pragma once
#include "dependencies.h"
struct TreeNode {
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
        int signal = 2;
        TreeNode* node;
        Node(TreeNode *a,int b = 2):node(a),signal(b){}
    };
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<Node> path;
        int result = 0;
        int count = 0;
        if (!root) return false;
        path.push(Node(root));
        result += path.top().node->val;
        while (!path.empty()) {
            if (path.top().signal == 2) {
                path.top().signal = 1;
                if (path.top().node->left) {
                    path.push(Node(path.top().node->left));
                    result += path.top().node->val;
                }
            }
            else if (path.top().signal == 1) {
                path.top().signal = 0;
                if (path.top().node->right) {
                    path.push(Node(path.top().node->right));
                    result += path.top().node->val;
                }
            }
            else {
                if (!path.top().node->left && !path.top().node->right) {
                    if (result == targetSum) return true;
                }
                result -= path.top().node->val;
                path.pop();
            }
        }
        return false;
    }
};
void test() {
    /*TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);*/
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution solution = {};
    cout << solution.hasPathSum(root, 5);
}