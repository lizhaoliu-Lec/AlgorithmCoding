/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
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
        traverse(root->right, rets);

        rets.push_back(root->val);
    }

    void iterative_stack(TreeNode* root, vector<int>& rets) {
        if (root == nullptr) {
            return;
        }

        stack<TreeNode*> st;
        st.push(root);
        TreeNode* last_pop = nullptr;

        // 后序遍历在中序的双层循环的基础上需要加入一个记录，专门记录上一次出栈的节点。
        /*
        1、如果栈顶元素非空且左节点存在，将其入栈，重复该过程。若不存在则进入第2步（该过程和中序遍历一致）
        2、判断上一次出栈节点是否当前节点的右节点，或者当前节点是否不存在右节点，
           满足任一条件，将当前节点输出，并出栈。
           否则将右节点压栈。跳至第1步
        */

        while (!st.empty()) {
            while (st.top()->left != nullptr) {
                st.push(st.top()->left);
            }

            while (!st.empty()) {
                if (st.top()->right == nullptr || st.top()->right == last_pop) {
                    rets.push_back(st.top()->val);
                    last_pop = st.top();
                    st.pop();
                } else if (st.top()->right != nullptr) {
                    st.push(st.top()->right);
                    break;
                }
            }
        }
    }
};
// @lc code=end
