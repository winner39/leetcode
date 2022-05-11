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
 
class Solution {
public:
    unordered_map<int, int> inMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < preorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return build(0, preorder.size() - 1, 0, preorder, inorder);
    }
    TreeNode* build(int left,int right,int target, vector<int>& preorder, vector<int>& inorder) {//根据先序遍历的根节点逐一确认左右儿子，如果不能直接确认则递进到左半右半子树中重复这一过程
        TreeNode* leftNode = nullptr, * rightNode = nullptr, * root = new TreeNode(preorder[target]);
        int in_index = inMap[preorder[target]];
        if (in_index + 1 == right) {//可以直接确认时
            rightNode = new TreeNode(inorder[in_index + 1]);
        }
        else if(right - in_index > 1){//不可以直接确认时
            rightNode = build(in_index + 1, right, target + in_index - left + 1, preorder, inorder);
        }
        //TreeNode默认为空，当上述两条分支都不满足，说明其不存在右子节点
        if (in_index - 1 == left) {
            leftNode = new TreeNode(inorder[in_index - 1]);
        }
        else if(in_index - left > 1){
            leftNode = build(left, in_index - 1, target + 1, preorder, inorder);
        }
        root->left = leftNode;
        root->right = rightNode;
        return root;
    }
};
void test() {
    vector<int> preorder = { 3, 9, 20, 15, 7 };
    vector<int> inorder = { 9, 3, 15, 20, 7 };
    Solution solution = {};
    solution.buildTree(preorder, inorder);
}