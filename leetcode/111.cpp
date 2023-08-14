/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        int ret = 0;
        queue<TreeNode*> q;

        if (root == nullptr) {
            return ret;
        }
        q.push(root);
        ret += 1;

        while (!q.empty()) {
            int q_len = q.size();
            for (int i = 0; i < q_len; i++) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left == nullptr && cur->right == nullptr) {
                    return ret;
                }

                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }

                
            }
            ret += 1;
        }

        return ret;
    }
};
// @lc code=end
