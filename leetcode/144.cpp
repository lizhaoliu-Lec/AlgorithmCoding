/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include <basic_struct/btree_node.h>
#include <bits/stdc++.h>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> rets;
        // traverse(root, rets);
        iterate_stack(root, rets);
        return rets;
    }

    void traverse(TreeNode* root, vector<int>& rets) {
        if (root == nullptr) {
            return;
        }

        rets.push_back(root->val);
        traverse(root->left, rets);
        traverse(root->right, rets);
    }

    /*
    栈实现前序遍历较简单，由于每次先输出根节点，再输出左节点随后是右节点。因此我的处理逻辑是：

    1、若栈非空输出根节点，并出栈
    2、将右节点压栈（如果存在）
    3、将左节点压栈（如果存在）
    4、重复第1步直到栈空

    注意：之所以先压右节点是考虑了栈的特性，这样在迭代过程中可以先拿到左节点处理
    */
    void iterate_stack(TreeNode* root, vector<int>& rets) {
        if (root == nullptr) {
            return;
        }

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();

            rets.push_back(cur->val);
            
            if (cur->right != nullptr) {
                st.push(cur->right);
            }
            if (cur->left != nullptr) {
                st.push(cur->left);
            }
        }
    }
};
// @lc code=end
