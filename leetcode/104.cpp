/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
#include "basic_struct/btree_node.h"
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
    int maxDepth(TreeNode* root) { return traverse(root); }

    int traverse(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left_depth = traverse(root->left);
        int right_depth = traverse(root->right);

        return 1 + max(left_depth, right_depth);
    }
};
// @lc code=end
