/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
#include <bits/stdc++.h>
#include "basic_struct/btree_node.h"
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rets;

        // traverse(root, rets);
        iterative_stack(root, rets);
        return rets;
    }

    void traverse(TreeNode* root, vector<int>& rets) {
        if (root == nullptr) {
            return;
        }

        traverse(root->left, rets);
        rets.push_back(root->val);
        traverse(root->right, rets);
    }

    void iterative_stack(TreeNode* root, vector<int>& rets) {
        if (root == nullptr) {
            return;
        }

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            // 该过程一直找到没有左节点的节点才停止
            while (!st.empty() && st.top()->left != nullptr) {
                st.push(st.top()->left);
            }

            // 此时的S.top()是一个没有left的节点，按照中序遍历的特性，可以将其直接输出。
            // while循环会一直将栈顶输出，直到遇到有右节点的节点，这样能保证栈中元素不会重复寻找左孩子
            while (!st.empty()) {
                TreeNode* cur = st.top();
                // 当前节点可以直接输出
                rets.push_back(cur->val);
                st.pop();

                // 如果当前节点有右节点，将右节点入栈
                if (cur->right != nullptr) {
                    st.push(cur->right);
                    break;
                }
            }
        }
    }
};
// @lc code=end
