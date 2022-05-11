#pragma once
#include "dependencies.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* blankNode = new TreeNode(0);
        string serial;
        if (root) {
            q.push(root);
            serial.append(to_string(root->val));
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    serial.append("," + to_string(node->left->val));
                }
                else {
                    serial.append(",#");
                }
                if (node->right) {
                    q.push(node->right);
                    serial.append("," + to_string(node->right->val));
                }
                else {
                    serial.append(",#");
                }
            }
        }
        return serial;




    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

    }
};